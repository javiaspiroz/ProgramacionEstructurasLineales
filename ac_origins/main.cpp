#include <array>
#include <cstdlib>
#include <fmt/core.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>
#include <range/v3/all.hpp>
#include <stdexcept>
#include <string>
#include <vector>

struct Target {
    std::string name{};
    int level{0};
    std::array<double, 3> location{};
    bool achieved{false};
};

auto main() -> int
{
    //vector de objetivos inicialmente vacío
    auto targets =std::vector<Target>{};
    //abrimos fichero, deserializamos el fichero military_camp.jsonl
    auto data_path = "D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//ac_origins//military_camp.jsonl";
    auto file = std::fstream{data_path, std::ios::in | std::ios::binary};
    //cargamos una de las líneas json
    auto json_line = std::string{};
    auto aux = Target{};
    while (std::getline(file, json_line)) {
        auto j = nlohmann::json::parse(json_line);
        j.at("name").get_to(aux.name);
        j.at("level").get_to(aux.level);
        j.at("location").get_to(aux.location);
        j.at("achieved").get_to(aux.achieved);
        //metemos en el objeto los datos almacenados en el aux
        targets.push_back(aux);
    }

    //ordenamos para que todos los tipos de objetos estén seguidos
    ranges::sort(targets, std::less{}, &Target::name);

    //funcion lambda para comparación de dos targets por nombre
    auto mismo_nombre = [](Target t1, Target t2) -> bool {
        return t1.name == t2.name;
    };

    //imprimimos los datos almacenados en el vector
    //for (Target t : targets){
        //std::cout t.name;
        //std::cout t.achieved;
        //otra forma
        //std::cout << fmt::format("Tipo: {}, conseguido: {}\n", t.name, t.achieved);
    //}
    
    //Identificamos los subgrupos del vector que contengan targets del mismo nombre mediante la operación group_by() e iteramos a través de ellos
    for (auto subgroup : targets | ranges::view::group_by(mismo_nombre)){//aqui | significa pipeline (concatenación de operaciones)
        //contamos cuantos targets hay detro del subgrupo, contamos cuántos están vivos e imprimimos la info
        auto total_targets = 0;
        auto achieved_targets = 0;
        for (Target t: subgroup){
            ++total_targets;
            if (t.achieved == true)
                ++achieved_targets;
        }
        //damos formato especial a la impresion : decimos que añadimos cosas, > justificado derecha, 15 longitud
        std::cout << fmt::format("{:>15} --> {}/{}\n", subgroup.begin()->name, achieved_targets, total_targets);
    }
    return EXIT_SUCCESS;
}