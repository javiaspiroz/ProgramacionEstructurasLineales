#include <cstdlib>
#include <fstream>
#include <fmt/format.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <range/v3/view/group_by.hpp>
#include <range/v3/algorithm/sort.hpp>
#include <vector>

using namespace std;

 struct Champion {                 
    string player, 
        country;
    int year;  // año de victoria              
};

auto main() -> int {
    auto champions = vector<Champion>{};
    auto data_path = "D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//prueba-integradora//roland_garros(1).jsonl";
    auto file = fstream(data_path, ios::in | ios::binary);
    if(!file){
        cerr << "Sin fichero";
        return EXIT_FAILURE;
    }
    //metemos los datos del json al vector
    auto json_line = string{};
    auto aux = Champion{};
    while(getline(file, json_line)){
        auto j = nlohmann::json::parse(json_line);
        j.at("country").get_to(aux.country);
        j.at("player").get_to(aux.player);
        j.at("year").get_to(aux.year);
        champions.push_back(aux);
    }

    //funciones lambda
    auto same_country = [](Champion const& c1, Champion const& c2) -> bool { return c1.country==c2.country; };
    auto same_player = [] (Champion const& c1, Champion const& c2) -> bool { return c1.player==c2.player; };

    ranges::sort(champions, less{}, &Champion::country);//ordenamos el vector

    auto wins_map = map<int, vector<string>, greater<>>{};//mapa

    for (auto group_country : champions | ranges::view::group_by(same_country)){
        cout << fmt::format("{:_^30}\n",group_country.begin()->country);//imprimimos el pais
        ranges::sort(group_country, less{}, &Champion::player);//ordenamos los jugadores del pais
        auto country_wins = 0;//numero de victorias de un mismo pais
        for (auto jugador : group_country | ranges::view::group_by(same_player)){
            auto total_wins = 0;//numero de victorias de un mismo jugador
            for (auto c : jugador){
                ++country_wins;
                ++total_wins;
            }
            cout << fmt::format("{} -> {}\n", jugador.begin()->player, total_wins);            
        }
        cout << '\n';//para aclarar el espaciado
        wins_map[country_wins].push_back(group_country.begin()->country);//metemos los datos en el mapa
    }

    //imprimimos los datos del mapa
    for (auto [w, country] : wins_map){
        if(w>=5){//imprimir solo los que han ganado al menos 5 veces
            for (auto p : country){
                cout << fmt::format("{} --> {}\n", p, w);
            }
        }        
    }

    return EXIT_SUCCESS;
}