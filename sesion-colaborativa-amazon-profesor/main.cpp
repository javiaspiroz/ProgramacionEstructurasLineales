#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <nlohmann/json.hpp>
#include <range/v3/numeric/accumulate.hpp>
#include<range/v3/algorithm/count_if.hpp>
#include <fmt/format.h>

//Solución hecha por el profesor en la siguiente clase

using namespace std;

using Dictionary = map<string, vector<double>>;

auto read_data() -> Dictionary{
    auto data = Dictionary{};
    auto path="D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//sesion-colaborativa-amazon-profesor//Automotive_5.json";
    //comprobamos que el fichero se abre
    if (auto ifs = fstream(path, ios::in | ios::binary)){
        auto json_line = string{}, product = string{};
        auto mark = 0.0;
        while (getline(ifs, json_line)){
            auto j =nlohmann::json::parse(json_line);
            j.at("asin").get_to(product);
            j.at("overall").get_to(mark);
            data[product].push_back(mark);
        }
        return data;
    }
    else{//fallo de fichero
        throw ios::failure{"unable to open the file"};
    }
}

auto main() -> int {
    auto amazon_data = read_data();

    //bucle que itere a través del mapa, de pareja clave-valor apareja c-v

    auto counter = ranges::count_if(amazon_data, [](auto const& kv_pair) -> bool {
        auto const& [prod, marks] = kv_pair;
        auto total = ranges::accumulate(marks, 0.0);
        return total/marks.size() >= 4.0;
    });

    cout << fmt::format("Percentage: {:.2f}%", //son :.2f hago que salgan solo dos decimales
                    100* static_cast<double>(counter) / amazon_data.size());

    return EXIT_SUCCESS;
}