#include <iostream>
#include <cstdlib>
#include <fmt/format.h>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/enumerate.hpp>
#include <range/v3/action/sort.hpp>
#include <range/v3/action/unique.hpp>
#include <range/v3/action/remove_if.hpp>
#include <range/v3/action/transform.hpp>
#include <string>
#include <vector>

struct Enemy{
    std::string type{};
    int level{};
};

struct Product {
    std::string type{};
    std::string brand{};
    double price;
};

auto main() -> int {
    namespace rv=ranges::view;
    namespace ra=ranges::action;

    auto nums = rv::iota(1); //vista de una secuncia de enteros desde 1 hasta infinito empezando en 1

    auto is_even = [](int i) -> bool {return i%2==0; };
    auto squared = [](int i) -> int {return i*i; };

    for (int i : nums | rv::take(8) | rv::filter(is_even) | rv::transform(squared)){
        std::cout << fmt::format("{}, ", i);
    }

    std::cout << "\n\n";//para arreglar el espaciado de la impresión

    auto characters = std::vector<std::string>{"Gandalf", "Boromir", "Saruman", "Bilbo"};
    for (auto [idx, name] : characters | rv::enumerate){
        std::cout << fmt::format("{}. {}\n", idx+1, name);
    }

    std::cout << "\n";//para arreglar el espaciado de la impresión

    auto nums2= std::vector<int>{5, -3, 1, 1, -3, 1, 5, 5};
    
    nums2 |= ra::sort | ra::unique;

    for (int i : nums2)
        std::cout << fmt::format("{} ", i);

    std::cout << "\n\n";//para arreglar el espaciado de la impresión

    auto enemies = std::vector<Enemy>{
        {"Saruman", 150}, {"troll", 45}, {"uruk-hai", 80}, {"orc", 25}, {"nazgul", 100}
    };

    auto level_below_50 = [] (Enemy const& e) -> bool{return e.level<50; };
    auto level_x2 = [] (Enemy const& e) -> Enemy {return Enemy{e.type, e.level*2}; };

    enemies |=ra::sort(std::greater(), &Enemy::level)
            | ra::remove_if(level_below_50) 
            | ra::transform(level_x2);

    for (Enemy const& e : enemies)
        std::cout << fmt::format("{}-->{}\n", e.type, e.level);

    //rellenar, cojer vector y ordenar mayor a menor precio, meter una marca y introducir un precio max y min
    auto products = std::vector<Product>{{"pantalón", "AB", 10.4}, {"vestido", "AB", 15.6}, {"camiseta", "ZY", 5.4}};

    //hago que metan los valores por parametro
    /*std::cout << "marca";
    std::string marca{};
    std::getline(std::cin, marca);
    std::cout << "max";
    auto max=double{};
    std::getline(std::cin, max);
    std::cout << "min";
    double min=0;
    std::getline(std::cin, min);*/

    auto price_below = [] (Product p) -> bool{return p.price>10.3; };
    auto price_above = [] (Product p) -> bool{return p.price<100.2; };
    auto brand = [] (Product p) -> bool {return p.brand.compare("AB"); };

    products |= ra::sort(std::greater(), &Product::price) | ra::remove_if(brand)
    | ra::remove_if(price_above) | ra::remove_if(price_below);

    for (Product const& p : products)//no acaba de imprimir
        std::cout << fmt::format("{} de {} a la venta por {}\n",p.type, p.brand, p.price);
    
    return EXIT_SUCCESS;
}