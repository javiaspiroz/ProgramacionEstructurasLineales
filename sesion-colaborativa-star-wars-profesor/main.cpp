#include <array>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <random>
#include <range/v3/algorithm/min_element.hpp>
#include <range/v3/action/shuffle.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/enumerate.hpp>
#include <string>

using namespace std;
using namespace std::chrono;
namespace rn = ranges;
namespace rv = ranges::views;
namespace ra = ranges::actions;

struct Point{
    double r{}, t{}; //coordenadas polares(radio y ángulo)
};

struct Character{
    string name;
    Point location{};
};

[[nodiscard]] auto heroes_villains() -> array<array<Character, 3>, 2>;

auto main(int, char**) -> int {
    auto const [heroes, villains] = heroes_villains();

    cout << fmt::format("{:_^50}\n", "Allies");
    for (Character const& h : heroes)
        cout << fmt::format("{:>20} | r: {:>4.2f} t: {:>4.2f}\n", h.name, h.location.r, h.location.t);

    cout << fmt::format("{:_^50}\n", "Enemies");
    for (Character const& v : villains)
        cout << fmt::format("{:>20} | r: {:>4.2f} t: {:>4.2f}\n", v.name, v.location.r, v.location.t);

    auto polar_distance = [ ]( Point const& p1, Point const& p2 ) -> double {
        return sqrt( pow(p1.r, 2) + pow(p2.r, 2) - 2 * p1.r * p2.r * cos(p2.t - p1.t) ); 
    };

    cout << fmt::format("{:_^50}\n", "Heroes vs Villains");
    for (Character const& h : heroes){
        /*auto dist_aux = 200.0;
        auto c_aux = Character{};
        for (Character const& v : villains){
            auto d = polar_distance(h.location, v.location);
            if(d < dist_aux){
                dist_aux=d;
                c_aux = v;
            }
        }*/
        //Sustituimos el bucle anterior usando ahora una biblioteca que busque el minimo
        auto comp = [&] (Point p1, Point p2){
            return polar_distance(p1, h.location) < polar_distance(p2, h.location);
        };
        auto iter = rn::min_element(villains, comp, &Character::location);
        cout << fmt::format("{:>20} vs {}\n", h.name, iter->name);
    }

    return EXIT_SUCCESS;
}

auto heroes_villains() -> array<array<Character, 3>, 2>{
    auto heroes = array{"Chewbacca",
                        "Han Solo",
                        "Leia Organa",
                        "Luke Skywalker",
                        "Obi-Wan Kenobi",
                        "R2-D2",
                        "Yoda" };

    auto villains = array{"Conde Dooku",
                        "Darth Maul",
                        "Darth Vader",
                        "Jabba el Hutt",
                        "Jango Fett",
                        "Grand Moff Tarkin",  
                        "Palpatine" };
    
    auto gen =mt19937{};
    gen.seed(steady_clock::now().time_since_epoch().count());
    
    auto radius = uniform_real_distribution{0.0, 100.0};
    auto angle = uniform_real_distribution{0.0, 2*3.141592};

    auto arena_heroes = array<Character, 3>{};
    for (auto [i, name] : (heroes |= ra::shuffle(gen)) | rv::take(3)| rv::enumerate){
        arena_heroes[i] = {name, {radius(gen), angle(gen)}};
    }

    auto arena_villains = array<Character, 3>{};
    for (auto [i, name] : (villains |= ra::shuffle(gen)) | rv::take(3)| rv::enumerate){
        arena_villains[i] = {name, {radius(gen), angle(gen)}};
    }

    return {arena_heroes, arena_villains};
}