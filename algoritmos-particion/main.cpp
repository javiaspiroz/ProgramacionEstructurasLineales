#include <cstdlib>
#include <fmt/format.h>
#include <functional>
#include <iostream>
#include <range/v3/algorithm/partition.hpp>
#include <range/v3/algorithm/stable_partition.hpp>
#include <range/v3/algorithm/find.hpp>
#include <range/v3/view/subrange.hpp>
#include <string>
#include <vector>

using namespace std;

struct Album {
    string title, band, genre;
};

auto main() -> int {
    /*//imprimimos la direccion de memoria de n a través del puntero a entero p
    auto n=int{0};
    int* p=&n;
    ++*p;
    cout << p;
    cout << *p; //aqui imprimimos el contenido de la direccion de memoria p, en este caso n*/

    /*auto album = Album{"Parachutes", "Coldplay", "classic"};
    Album* p = &album; //p es un puntero a album
    (*p).genre="pop";
    cout << fmt::format("Title: {}, Band: {}, Genre: {}", (*p).title, p->band, p->genre);//puedo usar el operador 
                                                                    //flecha o el punto pero es recomendable el flecha*/
    
    /*auto numeros = vector<int>{1,2,3,4,5,6,7,8,9,10};//alg de partición que redistribuye un vector según si cumple 
                                                    //una condición que irá al principio del vector
    
    auto iter = ranges::partition(numeros, [](int i){return i%2==0; });//omitimos el tipo retornado en la funcion lambda

    for (int i : ranges::subrange{numeros.begin(), iter})//imprimo pares
        cout << fmt::format("{}\n", i);
    cout << '\n';
    for (int i : ranges::subrange{iter, numeros.end()})//imprimo impares
        cout << fmt::format("{}\n", i);
    cout << '\n';

    //aqui el vector ya esta modificado por lo que el resultado no será el esperado según lo declarado
    auto stable_iter = ranges::stable_partition(numeros, [](int i){return i%2==0; });//ahora hacerlo con el mismo orden

    for (int i : ranges::subrange{numeros.begin(), stable_iter})//imprimo pares
        cout << fmt::format("{}\n", i);*/



    auto albums = std::vector< Album > {   
            {"the dark side of the moon", "pink floyd", "rock"},
            {"tubular bells", "mike oldfield", "new age"},
            {"ok computer", "radiohead", "rock"},
            {"the magnificent tree", "hooverphonic", "pop"},
            {"favourite worst nightmare", "arctic monkeys", "rock"},
            {"the four seasons", "vivaldi", "classical"},
            {"parachutes", "coldplay", "pop"},
            {"the suburbs", "arcade fire", "rock"},
            {"gran turismo", "the cardigans", "pop"}
   };

   cout << "Title to search: ";
   auto title_to_search = string{};
   getline(cin, title_to_search);

   auto iter = ranges::find(albums, title_to_search, &Album::title);
   if (iter !=albums.end()){//el disco solicitado está en la discografía
        auto found_genre = iter->genre;
        auto same_genre = [&](Album const& a){ return a.genre == found_genre; };

        ranges::stable_partition(iter, albums.end(), same_genre);//ordenamos los discos
        ranges::stable_partition(albums.begin(), iter, not_fn(same_genre));//not_fn justo lo contrario de la funcion

        for (Album const& a : albums)
            cout << fmt::format("'{:>25}' by '{:<15}' | {}\n", a.title, a.band, a.genre);
   }
   else{
        cout << "Sorry! Not on the list";
   }

    return EXIT_SUCCESS;
}