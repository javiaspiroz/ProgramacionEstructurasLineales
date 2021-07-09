#include <chrono>
#include <cstdlib>
#include <fstream>
#include <fmt/format.h>
#include <iostream>
#include <vector>
#include <range/v3/algorithm/rotate.hpp>
//include del ejemplo de uso equal_range
#include <range/v3/algorithm/equal_range.hpp>
#include <range/v3/view/subrange.hpp>
//includes de la ultima parte del codigo
#include <range/v3/view/unique.hpp>
#include <range/v3/view/remove_if.hpp>
#include <range/v3/action/sort.hpp>
#include <range/v3/action/transform.hpp>

using namespace std;

struct Enemy{
    char type;
    int level;
};

auto main() -> int {
    //ejemplo de complejidad usando rotate
    /*auto v = vector{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    auto first = v.begin()+1;//iterador que apunta a la 'b'
    auto last = v.begin()+4;//iterador que apunta a la 'e'
    auto position = v.begin()+6;//iterador que apunta a 'g'

    ranges::rotate(first, last, position);

    for (char c : v){
        cout << c << ' ';
    }*/

    //ejemplo usando equal_range

    /*auto enem = vector<Enemy>{ {'a', 5}, {'b', 8}, {'c', 1}, {'c', 7}, {'c', 5}, {'z', 4}, {'e', 3} };
    auto [first, last] = ranges::equal_range(enem, 'c', less{}, &Enemy::type);
    for (Enemy const& e : ranges::subrange{first, last}){
        cout << fmt::format("{}->{}\n", e.type, e.level);
    }*/

    //ejemplo mezclando views y actions de la biblioteca ranges

    namespace rn=ranges;
    namespace rv=ranges::view;
    namespace ra=ranges::action;

    auto es_impar = [](int i){return i%2 != 0; };
    auto multiplica_por_2 = [] (int i){ return i*2; };

    auto nums = vector{1,1,1,4,4,7,7,2,2,2,3,3};
    auto modf = nums | rv::unique
                    | rv::remove_if(es_impar)
                    | rn::to<vector>
                    | ra::sort
                    | ra::transform(multiplica_por_2);

    for (int n : modf)
        cout << n << ' ';

    return EXIT_SUCCESS;
}