#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include <fmt/format.h>
#include <string>
#include <range/v3/algorithm/stable_sort.hpp>
#include <range/v3/view/group_by.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/set_algorithm.hpp>
#include <range/v3/view/split_when.hpp>
#include <range/v3/algorithm/find.hpp>

using namespace std;

struct Champion {                 
    string player, country;
    int year;
};

auto main() -> int {
    auto records = map< int, vector<Champion>, greater<> >{};
    auto champions = vector<Champion>{}; //metemos los datos del fichero en un vector

    auto data_path = "D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//sesion-colaborativa-extra-roland-garros//roland_garros.jsonl";
    auto file = ifstream(data_path, ios::in | ios::binary);
    if (!file){
        cerr << "sin fichero";
        return EXIT_FAILURE;
    }
    
    for (auto json_line = string{}; getline(file, json_line); ){
        auto j = nlohmann::json::parse(json_line);
        champions.push_back(
            {
                .player = j.at("player"),
                .country = j.at("country"),
                .year = j.at("year")
            }
        );
    }

    ranges::stable_sort(champions, std::less{}, &Champion::player);

    auto same_player = [](Champion const& c1, Champion const& c2){ return c1.player == c2.player; };

    for (auto player_grp : champions | ranges::view::group_by(same_player)){
        auto years = vector<int>{};
        for (Champion const& c : player_grp){
            years.push_back(c.year);
        }

        auto complete = ranges::views::iota(years[0], years[years.size()-1] +1 );//genero el rango de los años en los que ha ganado
        auto diff = ranges::views::set_difference(complete, years);

        auto is_delimiter = [&](int n){ return ranges::find(diff, n) != diff.end(); };

        for (auto wins_grp : complete | ranges::views::split_when(is_delimiter)){
            auto consecutive_years = ranges::distance(wins_grp);
            records[consecutive_years].push_back({
                .player = player_grp.begin()->player,
                .country = player_grp.begin()->country,
                .year = *wins_grp.begin()
            });
        }
    }

    //imprimimos la informacion
    for(auto const& [consecutive_years, players] : records){
        cout << fmt::format("{} years in a row\n", consecutive_years);
        for (Champion const& c : players){
            cout << fmt::format("{} -> {}\n", c.player, c.year);
        }
    }

    return EXIT_SUCCESS;
}