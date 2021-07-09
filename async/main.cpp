#include <chrono>
#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <range/v3/view/iota.hpp>
#include <vector>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

//estamos usando programación concurrente

auto do_1() -> string{
    this_thread::sleep_for(6s);//hacemos esperar 6s para mostrar el resultado
    return "do_1 has finished";
}

auto do_2() -> string{
    this_thread::sleep_for(7s);
    return "do_2 has finished";
}

auto main() -> int {
    //Prueba básica con creación de hilos simple
    /*auto start = high_resolution_clock::now();
    //auto s_1 = do_1();//aquí los ejecutamos 1º s1 y despues s2
    future<string> ftr = async( launch::async, do_1);//llamada asincrona, que hace que 1 y 2 se ejecuten en hilos diferentes
    auto s_2 = do_2();
    auto s_1= ftr.get();//esperamos para obtener el primer string y lo obtenemos
    auto end = high_resolution_clock::now();
    auto total_time = duration_cast<seconds>(end-start).count();

    cout << fmt::format("s1{}, s2:{}\nTotal time: {} secs\n", s_1, s_2, total_time);*/


    //Empezamos otro ejemplo, en el que sumamos un vector de una capacidad muy grande

    //averiguamos el numero de hilos(nucleos) disponibles en nuestro ordenador en mi caso 8
    auto num_threads = static_cast<int>(thread::hardware_concurrency());
    if (num_threads==0)
        num_threads=1;
    //cout << num_threads;

    vector<int> v = ranges::view::iota(1, 50'000'000) | ranges::to_vector;
    //cout << v[0];

    auto operation = [&v](int first, int last){//que hace??
        auto total = 0;
        for (auto i = first; i<last; ++i){
            total+=v[i];
        }
        return total;
    };

    auto total_sz = static_cast<int>(v.size());
    auto chunk_sz = total_sz/num_threads;
    auto first=0;
    auto last = chunk_sz;
    auto futures = vector<future<int>>{};
    //los num_therads-1 primero bloques del vector son operados por hilos independencia
    for (auto i=0; i<num_threads-1; ++i){
        futures.push_back(async(launch::async, operation, first, last));
        first += chunk_sz;
        last+= chunk_sz;
    }
    //main se hace cargo del último bloque del vector
    auto sum_main = operation(first, total_sz);

    for (auto& ftr : futures){
        sum_main += ftr.get();
    }

    return EXIT_SUCCESS;
}