#include <iostream>
#include <random>
#include <functional>
#include <cstdlib>
#include <fmt/format.h>
#include <chrono>
#include <string>
#include <range/v3/algorithm/partition.hpp>
#include <range/v3/view/subrange.hpp>

//Autores: Javier Aspiroz, Solange Román, Eliseo Nguema

using namespace std;

struct Point {
    double x{}, y{}, z{};
};

struct Sable_guard {
    Point location{};
    double distance{};
    bool alert    = true,
        attack = true;
};

auto main() -> int {
    auto guards = vector<Sable_guard>{};//creamos el vector con todos los guardias
    //creación del algoritmo para crear los numeros aleatorios
    auto gen = mt19937{};
    gen.seed(chrono::steady_clock::now().time_since_epoch().count());

    auto distr = uniform_real_distribution{-15.0, 15.0};
    auto rand = bind(distr, gen);
    //funcion que calcula la distancia del guardia a spiderman
    auto euclidean_distance = [] (Point const& p) -> double{
        return sqrt(pow(p.x,2) + pow(p.y,2) + pow(p.z,2));
    };
    
    for (auto i=0u; i<25; ++i){//creamos la posición de cada guardia metiante numeros aleatorios
        Point aux = {rand(), rand(), rand()};
        auto guard=Sable_guard{};
        guard.location=aux;
        //calculamos la distancia al centro llamando a la función y determinamos el valor de attack y alert
        guard.distance=euclidean_distance(guard.location);
        if (guard.distance<5.0){
            guard.attack=true;
        }
        else{
            guard.attack=false;
        }
        if (guard.distance<10.0){
            guard.alert=true;
        }
        else{
            guard.alert=false;
        }
        guards.push_back(guard);
    }
    //empezamos a usar los algoritmos de particion
    auto alert_iter = ranges::partition(guards, [](Sable_guard i){return i.alert==true; });
    auto attack_iter = ranges::partition(guards, [](Sable_guard i){return i.attack==true; });

    cout << "Attacking:\n";
    for (Sable_guard& i : ranges::subrange{guards.begin(), attack_iter})
        cout << fmt::format("{}, {}, {} -> distance: {} m\n", i.location.x, i.location.y, i.location.z, i.distance);

    cout << "\nOn alert:\n";
    for (Sable_guard& i : ranges::subrange{attack_iter, alert_iter})
        cout << fmt::format("{}, {}, {} -> distance: {} m\n", i.location.x, i.location.y, i.location.z, i.distance);

    return EXIT_SUCCESS;
}