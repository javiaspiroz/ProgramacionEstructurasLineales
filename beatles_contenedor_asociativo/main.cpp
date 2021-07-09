#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
//bibliotecas no estandar
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <range/v3/algorithm/sort.hpp>

auto main() -> int {
    //creamos un mapa vacío
    using namespace std;//para ahorrar poner los std
    auto bands = map<string, vector<string>>{};
    //introducimos la info a mano los grupos musicales
    bands["The Beatles"] = {"Paul McCartney", "John Lennon", "Ringo Starr", "George Harrison"};
    bands["Swedish House Mafia"] = {"Axwell", "Steve Angello", "Sebastian Ingrosso"};
    bands["Pink Floyd"] = {"Nick Mason", "Syd Barrett", "Roger Waters", "Richard Wright", "David Gilmour", "Bob Klose"};
    bands["Arctic Monkeys"] = {"Alex Turner", "Matt Helders", "Jamie Cook", "Nick O'Malley", "Andy Nicholson", "Glyn Jones"};
    bands["Arcade Fire"] ={"Win Butler", "Regine Chassagne", "Richard Reed Parry", "Tim Kingsbury", "William Butler", "Jeremy Gara"};
    bands["Radiohead"] = {"Thom Yorke", "Jonny Greenwood", "Colin Greenwood", "Ed O'Brien", "Philip Selway"};

    //leemos desde la terminal el grupo a buscar
    auto band_to_search=string{};//string auxiliar
    cout << "Search a band: ";
    getline(cin, band_to_search);//usuario introduce el nombre del grupo

    //buscamos el grupo en el mapa
    if(auto it = bands.find(band_to_search); it!= bands.end()){//tambien se podria inicializar it fuera del if else
        //ordenamos los nombres de los integrantes
        ranges::sort(bands[band_to_search]);
        cout << fmt::format("{:_^30}:\n", band_to_search);//damos algo mas de formato _ se repite hasta completar 30 caracteres ^ y centramos
        for (string const& member :bands[band_to_search])//con & evitamos copiarlo y así ahorrar memoria
            cout << fmt::format("{:^30}\n", member);        
    }
    else{
        cout <<"Not on the list. Sorry!\n";
    }  
    //creamos el archivo json line
    auto file = fstream{"bands.jsonl", ios::out | ios::binary};
    //estructura del objeto json: {"band" : ***}
    //serializamos el mapa en un fichero JSON Line
    for (auto const& [band, list] : bands){
        auto j = nlohmann::json{};
        j["band"]=band;
        j["members"]=list;
        file << j << '\n';
    }
    return EXIT_SUCCESS;
}