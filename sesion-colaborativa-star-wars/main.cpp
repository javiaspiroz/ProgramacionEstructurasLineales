#include <cstdlib>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <functional>
#include <range/v3/algorithm/shuffle.hpp>
#include <fmt/format.h>

//Javier Aspiroz, Sebastian Quinayas, Javier Perez y Solange Roman

using namespace std;

struct Point {
    double r,        // radio >= 0
    t;        // angulo [0, 2*pi)
};
   
struct Character {
    string name;
    Point location;
};

auto main() -> int{
    auto heroes = vector<string>{
                                "Chewbacca",
                                "Han Solo",
                                "Leia Organa",
                                "Luke Skywalker",
                                "Obi-Wan Kenobi",
                                "R2-D2",
                                "Yoda" };

    auto villains = vector<string>{
                                 "Conde Dooku",
                                 "Darth Maul",
                                 "Darth Vader",
                                 "Jabba el Hutt",
                                 "Jango Fett",
                                 "Grand Moff Tarkin",  
                                 "Palpatine" };

    //creacion del algoritmo para crear los numeros aleatorios
    auto gen = mt19937{};
    gen.seed(chrono::steady_clock::now().time_since_epoch().count());

    auto radius_distr = uniform_real_distribution{0.0, 100.0};
    auto angle_distr = uniform_real_distribution{0.0, 2*3.141592};
    ranges::shuffle(heroes, gen);
    ranges::shuffle(villains, gen);

    //Creamos los vectores de tipo Character
    auto perH = vector<Character>{};
    auto perV = vector<Character>{};
    for (auto i=0u; i<3;++i){//
        perH.push_back({heroes[i], {radius_distr(gen), angle_distr(gen)} });
        perV.push_back({villains[i], {radius_distr(gen), angle_distr(gen)} });
    }

    //Imprimimos los vectores finales de enemigos y heroes
    cout << fmt::format("{:_^50}\n","Allies");
    for (auto h : perH){
        cout << fmt::format("{}, r = {} m, t = {} rad\n", h.name, h.location.r, h.location.t);
    }
    cout << fmt::format("{:_^50}\n","Enemies");
    for (auto v : perV){
        cout << fmt::format("{}, r = {} m, t = {} rad\n", v.name, v.location.r, v.location.t);
    }

    auto distance = [ ]( Point const& p1, Point const& p2 ) -> double {//Funcion lambda que calcula la distancia entre dos Characters
        return sqrt( pow(p1.r, 2) + pow(p2.r, 2) - 2 * p1.r * p2.r * cos(p2.t - p1.t) ); 
    };

    //Comparamos los heroes con los villanos
    cout << fmt::format("{:_^50}\n","Heroes vs Villains");;
    auto dist= double{200};
    string name{};
    for (auto h : perH){
        for (auto v : perV){
            if(distance(h.location, v.location)<dist){
                dist=distance(h.location, v.location);
                name=v.name;
            }
        }
        //Imprimimos los enfrentamientos
        cout << fmt::format("{} vs {}\n", h.name, name);
        dist=200.0;//Restablecemos el valor de la distancia inicial
    }
    return EXIT_SUCCESS;
}