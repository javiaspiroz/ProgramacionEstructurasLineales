#include <cstdlib>
#include <fmt/format.h>
#include <memory>
#include <iostream>
#include <string>
#include <cassert>//incluido al cambiar al msi

using namespace std;

struct S {
    int i;
    char a;
    //int i; lo subimos arriba para que el tamaño sea mas efectivo, de esta forma saldria 12
    char b;
};

struct Health {
    int hit_points{10};
    int lives{5};
};

struct Dvd {
    string title{};
    double price{0.0};
};

auto decrease_hitpoint(Health* ht) -> void{
    /*if (!ht)
        abort();
        (*ht).hit_points/=2;*/
    assert(ht != nullptr);
    ht->hit_points/=2;
}

auto main() -> int {
    /*cout << alignof(S);
    cout << '\n';
    cout << sizeof(S);*/

    /*auto i= int{7};
    int* p = &i; //puntero al entero i (tipo int*)
    cout << sizeof(int*) << '\n';

    *p = 8;
    cout << *p;*/

    //auto h = Health{10, 5};
    /*Health* p = &h; //puntero al objeto H (tipo Health*)

    (*p).hit_points = 2;
    cout << fmt::format("{} , {}", (*p).hit_points, (*p).lives);
    decrease_hitpoint(h);
    cout << fmt::format("{} , {}", h.hit_points, h.lives);*/

    /*decrease_hitpoint(&h);
    cout << fmt::format("{} , {}", h.hit_points, h.lives);*/

    Dvd* p = new Dvd[12]{};

    //para acceder al primer dvd
    (*p).title="Star Wars IV"; //otra forma: p->title=...
    (*p).price=11.95;

    //usamos la aritmetica de punteros, para acceder en este caso al 3 hueco
    (p+2)->title="Avatar";
    (p+2)->price=8.0;//forma desarrollada y más conveniente: p[2].price=...

    delete p;

    //como se hace ahora usando smart pointers
    unique_ptr<Dvd[]> d = make_unique<Dvd[]>(12);
    p[2].title="Avatar";
    p[2].price=4.5;

    return EXIT_SUCCESS;
}