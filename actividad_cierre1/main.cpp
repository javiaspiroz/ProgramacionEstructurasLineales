#include <iostream>
#include <cstdlib>
#include <fmt/format.h>
#include <string>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include <range/v3/algorithm/sort.hpp>
#include <range/v3/view/group_by.hpp>

using namespace std;

//Activida deserrollada por Javier Aspiroz 21957644

struct Character  {
    string name,    // nombre 
        race,      // raza
        realm;    // reino
    bool bearer;    // portador del anillo?  
};

auto main() -> int{
    //Pasamos todos los datos del fichero al vector characters
    auto characters = vector<Character>{};
    auto data_path = "D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//actividad_cierre1//lord_of_the_rings.jsonl";
    auto file = fstream(data_path, ios:: in | ios::binary);
    if (!file){
        cerr << "Sin fichero";
        return EXIT_FAILURE;
    }
    auto json_line=string{};
    auto aux=Character{};
    while (getline(file, json_line)){
        auto j=nlohmann::json::parse(json_line);
        j.at("name").get_to(aux.name);
        j.at("race").get_to(aux.race);
        j.at("realm").get_to(aux.realm);
        j.at("bearer").get_to(aux.bearer);
        characters.push_back(aux);
    }

    //Funciones lambda requeridas
    auto same_race = [](Character c1, Character c2) -> bool { return c1.race==c2.race; };

    auto same_realm = [] (Character c1, Character c2) -> bool { return c1.realm==c2.realm; };

    auto is_ring_bearer = [] (Character c) -> bool { return c.bearer==true; };

    //Hacemos que el usuario introduzca una raza
    auto race_to_find = string{};

    cout << "Introduce a race: ";
    getline(cin, race_to_find);

    //Ordenamos el vector por orden lexicografico de raza

    ranges::sort(characters, less{}, &Character::race);

    //comprobamos si la raza introducida esta en nuestro vector

    for (auto race_group : characters | ranges::view::group_by(same_race)){
        auto race_name=race_group.begin()->race;

        if (race_name==race_to_find){
            for(auto realm_group : race_group | ranges::view::group_by(same_realm)){
                ranges::sort(race_group, less{}, &Character::realm);
                cout << fmt::format("{:_^35} \n", realm_group.begin()->realm);
                for (auto c : realm_group){
                    cout << fmt::format("{:^35} ", c.name);
                    if (is_ring_bearer(c)){//imprimimos si es portador del anillo
                        cout << "[ring-bearer]";
                    }
                    cout << '\n';//imprimimos newline despues de cada personaje
                }
            }
        }
    }
    return EXIT_SUCCESS;
}