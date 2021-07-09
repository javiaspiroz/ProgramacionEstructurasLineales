#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <future>
#include <utility>
#include <memory>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

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

struct Player_no_locality{
    string username{},
        keyword{},
        security_question{},
        security_answer{},
        name{};
    int level{0};
    bool is_playing{false};
};

auto main() -> int {
    auto gen = mt19937{};
    gen.seed(chrono::steady_clock::now().time_since_epoch().count());
    
    auto playing_distr = bernoulli_distribution{0.25}; //true 1/4 of the times
    auto level_distr = uniform_int_distribution{1, 15};

    auto players = vector<Player/*_no_locality*/>{};//inicialmente vacio
    players.reserve(10'000'000);//creamos diez millones de jugadores

    for (auto i=0; i<10'000'000; i++){
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

        //parte de codigo para cuando no haya localidad
        /*auto player=Player_no_locality{
            .username="abcdefgh",
            .keyword="abcdefgh",
            .security_question="abcdefgh",
            .security_answer="abcdefgh",
            .name ="abcdefgh",
            .level=level_distr(gen),
            .is_playing=playing_distr(gen)
        };*/
        
        players.push_back(move(player));
    }

    //averiguamos el numero de hilos (nucleos) disponibles en nuestro ordenador (en mi caso 8)
    auto num_threads = thread::hardware_concurrency()/*1u*/;
    if (num_threads==0)
        num_threads=1;
    //cout << num_threads;   

    auto operation = [&players](unsigned first, unsigned last){//total jugadores online
        auto total = 0;
        for (auto i = first; i<last; ++i){//hacemos que solo cuente si esta online
           if(players[i].is_playing){
               ++total;
           } 
        }
        return total;
    };

    auto start = chrono::steady_clock::now();
    
    auto total_sz = players.size();
    auto chunk_sz = total_sz/num_threads;
    auto first=0;
    auto last = chunk_sz;
    auto futures = vector<future<int>>{};
    //los num_therads-1 primero bloques del vector son operados por hilos independencia
    for (auto i = 0u; i < num_threads-1; ++i){
        futures.push_back(async(launch::async, operation, first, last));
        first += chunk_sz;
        last += chunk_sz;
    }
    //main se hace cargo del último bloque del vector
    auto sum_main = operation(first, total_sz);

    for (auto& ftr : futures){
        sum_main += ftr.get();
    }
    
    auto end = chrono::steady_clock::now();
    cout << fmt::format("Number of online players: {} | Time: {} ms\n", sum_main, 
                        duration_cast<chrono::milliseconds>(end-start).count());

    return EXIT_SUCCESS;
}