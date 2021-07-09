#include <chrono>
#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <random>
#include <range/v3/algorithm/count_if.hpp>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using namespace fmt;
namespace r = ranges;

struct Player_security_info {
    string username{},
        keyword{},
        security_question{},
        security_answer{};
};

struct Player{
    string name{};
    unique_ptr<Player_security_info> security_info{nullptr};
    int level{0};
    bool is_playing{false};
};

auto main() -> int {
    auto gen = mt19937{};
    gen.seed(chrono::steady_clock::now().time_since_epoch().count());
    
    auto playing_distr = bernoulli_distribution{0.25}; //true 1/4 of the times
    auto level_distr = uniform_int_distribution{1, 15};

    //--------------------------------------

    auto players = vector<Player>{};//inicialmente vacio
    players.reserve(1'000'000);//creamos un millon de jugadores

    for (auto i=0; i<1'000'000; i++){
        auto info = make_unique<Player_security_info>(
            Player_security_info{
                .username="abcdefgh",
                .keyword="abcdefgh",
                .security_question="abcdefgh",
                .security_answer="abcdefgh"
            }
        );
    
        auto player=Player{
            .name ="abcdefgh",
            .security_info = move(info),
            .level=level_distr(gen),
            .is_playing=playing_distr(gen)
        };
        players.push_back(move(player));
    }

    auto start = chrono::steady_clock::now();
    //número de jugadores en línea
    auto num_players = r::count_if(players, &Player::is_playing);//dos opcinones para poner la condicion la que esta puesta y 
                                        //[](Player const& p)->bool{ return p.is_playing; }
    auto end = chrono::steady_clock::now();
    cout << format("Number of online players: {} | Time: {} milisecs\n", num_players, 
                        duration_cast<chrono::milliseconds>(end-start).count());


    return EXIT_SUCCESS;
}