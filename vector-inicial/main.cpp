#include <iostream>
#include <cstdlib>
#include <string>
#include <fmt/format.h>
#include <array>

using namespace std;

struct Dvd{
    string title{};
    double price{};
};

template<typename T>
class Dynarray { //array dinamico
    unique_ptr<T[]>p_; //puntero al primer elemento del array
    unsigned size_; //num de DVDs del array
public:
    Dynarray(unsigned n)
    : p_{make_unique<T[]>(n)}, size_{n}

    { }

    auto operator[](unsigned idx) -> T& {return p_[idx]; }
    auto size() -> unsigned {return size_; }
};

auto main() -> int {

    cout << "Number of DVDs: ";
    auto n=0u;
    (cin >> n).ignore();

    //creamos una estructura que vive en el free store:
    auto dvds = Dynarray<Dvd>{n};

    for (auto i=0u; i < dvds.size(); ++i){
        cout << fmt::format("Title of DVD#{}: ", i+1);
        getline(cin, dvds[i].title);
        cout << fmt::format("Price of DVD#{}: ", i+1);
        (cin >> dvds[i].price).ignore();
    }

    for (auto i=0u; i < n; ++i){
        cout << fmt::format("Title: {:>15} Price: {}\n", dvds[i].title, dvds[i].price);
    }

    return EXIT_SUCCESS;
}