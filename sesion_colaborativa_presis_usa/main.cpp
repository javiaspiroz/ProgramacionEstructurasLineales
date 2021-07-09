#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include <range/v3/all.hpp>
#include <fmt/format.h>
#include <stdexcept>

//Autores: Javier Aspiroz, Pedro Castillo y Solange Román

struct President {
    std::string name{};
    std::string party{};
    int end{0};
    int start{0};
};

auto main() -> int {
    auto president = std::vector<President>{};
    auto data_path = "D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//sesion_colaborativa_presis_usa//american_presidents.jsonl";
    auto file = std::fstream(data_path, std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "sin fichero";
        return EXIT_FAILURE;
    }
    //pasamos los datos del jsonl al vector president
    auto json_line =std::string{};
    auto aux = President{};
    while (std::getline(file, json_line)){
        auto j =nlohmann::json::parse(json_line);
        j.at("name").get_to(aux.name);
        j.at("party").get_to(aux.party);
        j.at("end").get_to(aux.end);
        j.at("start").get_to(aux.start);
        president.push_back(aux);
    }
    //ordenamos los presidentes por partido
    ranges::sort(president, std::less(), &President::party);
    //funcion lambda que compara si dos presidentes son del mismo partido
    auto mismo_party =[](President p1, President p2)-> bool {
        return p1.party==p2.party;
    };
    //bucle para ordenar presidentes segun su partido
    for (auto subgroup : president | ranges::view::group_by(mismo_party)){
        auto total_years=0;
        std::cout << fmt::format("{:_^60}\n", subgroup.begin()->party);
        ranges::sort(subgroup, std::less(), &President::start);
        //imprimimos los presidentes y calculamos los años de mandato
        for (auto paux : subgroup){
            std::cout << fmt::format("{:^60} {}-{}\n", paux.name, paux.start, paux.end);
            total_years+= paux.end-paux.start;
        }
        //Calculamos el porcentaje del partido en el poder
        auto percentage = (total_years*100)/243;
        std::cout << fmt::format("{:-^60}\n","");
        std::cout << fmt::format ("Total years: {}, {}%\n", total_years, percentage);
    }    
    return EXIT_SUCCESS;
}