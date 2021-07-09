#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <nlohmann/json.hpp>
#include <range/v3/view/map.hpp>
#include <fmt/format.h>

//Autores: Javier Aspiroz, Pedro Castillo, Eliseo Nguema Chema

struct Product {
    std::string product{};
    double grade = 0.0;
};

auto main() -> int {
    //creamos el diccionario
    auto products = std::map<std::string, std::vector<double>>{};
    auto data_path="D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//sesion-colaborativa-amazon//Automotive_5.json";
    auto file = std::fstream(data_path, std::ios::in);
    if (!file){
        std::cerr << "sin fichero";
        return EXIT_FAILURE;
    }
    //obteneos los valores de JSON y los metemos en el map
    auto json_line=std::string{};
    auto product= std::string{};
    double grade = 0;
    while (std::getline(file, json_line)){
        auto j = nlohmann::json::parse(json_line);
        j.at("asin").get_to(product);
        j.at("overall").get_to(grade);
        products[product].push_back(grade);
    }
    //numero de productos con nota mayor que 4
    int product_good=0;
    //bucle que recorre el map devolviendonos los valores requeridos
    for (std::string prod : products | ranges::view::keys){
        
        double total_grade=0.0;
        //bucle para recorrer el vector de valoraciones
        for (auto i : products[prod]){
            total_grade+=i;
        }
        double average = total_grade/(double) products[prod].size();
        if (average>4){
               product_good++;
            }
        std::cout << fmt::format("{}: {}\n", prod, average);
    }
    auto percentage = (product_good*100)/products.size();

    std::cout << fmt::format("Porcentaje de productos con valoracion media mayor que 4: {}%", percentage);

    return EXIT_SUCCESS;
}