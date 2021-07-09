#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename Bidirectional_iterator, typename Compare>
auto insertion_sort(Bidirectional_iterator first, Bidirectional_iterator last, Compare comp) -> void {
    if (first==last)//rango a ordenar esta vacio
        return;
    
    auto p = first;//copia del iterador first, referencia a "S[0]"
    ++p;//p apunta a "S[1]" o es igual a last

    while(p != last){
        auto val = move(*p);//hacemos una copia de seguridad del dato referenciado por p
        auto q = p;//iterador que es copia de p
        do{
            auto previous = q;
            --previous;
            if(comp(*previous, val))
                break;
            *q = move(*previous);
            --q;
        }
        while (q != first);
        *q = val;
        ++p;
    }
}

template<typename Bidirectional_iterator>
auto insertion_sort(Bidirectional_iterator first, Bidirectional_iterator last) -> void {
    insertion_sort(first, last, [](auto const& a, auto const& b){return a<b; } );
}

auto main() -> int {
    //usando vector
    /*auto v = vector{1,2,3,4,5,6,7};*/
    //auto iter = v.begin();//este iter apunta al comienzo del vector, iter "es" un int*, tipo del iter: vector<int>::iterator
    /*iter += 4;
    cout << *iter;*/

    /*usando list
    auto v = list{1,2,3,4,5,6,7};
    auto iter = v.begin();*/
    //+=4;no compila porque el iterador recorre posiciones consecutivas y la lista no tienen que porque estar guardada asi
    //++iter;//habria que hacerlo de esta forma
    /*++iter;
    ++iter;
    ++iter;
    cout << *iter;*/
    //la lista tiene iteradores de tipo bidireccionales y el vector tiene iteradores de tipo aleatorio

    //vamos a implementar el insertion sort
    auto nums= list{-3,5,0,4,2,-6,12};
    insertion_sort(nums.begin(), nums.end(), [](auto a, auto b){return a > b; } );

    //forma para ordenar los 4 ultimos elementos
    /*auto iter = nums.begin();
    ++iter; ++iter; ++iter;
    insertion_sort(iter, nums.end(), [](auto a, auto b){return a > b; } );*/

    for (auto i : nums)//imprimimos la lista ordenada
        cout << i << ' ';

    return EXIT_SUCCESS;
}