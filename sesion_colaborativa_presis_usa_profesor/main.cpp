#include <fmt/format.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <range/v3/algorithm/sort.hpp>
#include <range/v3/view/group_by.hpp>

using namespace std;

struct President{
    string name{}, party{};
    int start{}, end{};
};

[[nodiscard]] auto read_data () -> vector<President>;//avisa de que te has olvidado capturar la variable,
                                                        //mediante un atributo

auto main() -> int
try{
    auto presidents = read_data();

    ranges::sort(presidents, less{}, &President::party);//ordenamos alfabeticamente por nombre de partido

    auto same_party = [](President const& p1, President const& p2) -> bool { return p1.party==p2.party; };

    //vistamos cada subgrupo/partido a través de una operación group_by
    for (auto party_grp : presidents | ranges::view::group_by(same_party)){
        auto prs1 = *party_grp.begin();
        cout << fmt::format("{:_^40}\n", prs1.party);
        //otra forma 
        /*auto party_name = party_grp.begin()->party;
        cout << fmt::format("{_^40}\n", party_name);*/
        //ordenamos los presidentes de este partido poraño de inicio de mandato
        double total = 0.0;
        ranges::sort(party_grp, less{}, &President::start);
        for (President const& p : party_grp){
            cout << fmt::format("{:>25} {}-{}\n", p.name, p.start, p.end);
            total += p.end - p.start;
        }
        cout << fmt::format("{:-40}\n", "") << fmt::format("Total years : {}, {:.2f}%\n", total, (100*total)/243);
    }
    return EXIT_SUCCESS;
}
catch(exception const& e){
    cerr << e.what();
    return EXIT_FAILURE;
}

auto read_data () -> vector<President>{
    auto presidents = vector<President>{};

    auto data_path="D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//sesion_colaborativa_presis_usa_profesor//american_presidents.jsonl";
    auto file =fstream{data_path,ios::in | ios::binary};
    if (!file)
        throw runtime_error{"Unable to open the file"};
    
    auto json_line = string{};
    auto pres_aux = President{};
    while(getline(file, json_line)){
        auto j = nlohmann::json::parse(json_line);
        j.at("name").get_to(pres_aux.name);
        j.at("party").get_to(pres_aux.party);
        j.at("end").get_to(pres_aux.end);
        j.at("start").get_to(pres_aux.start);
        presidents.push_back(pres_aux);
    }
    return presidents;
}