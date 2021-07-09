#include <iostream>
#include <cstdlib>
#include <string>
#include <fmt/format.h>
#include <memory>
#include <string>

using namespace std;

template<typename T>
class Dynarray {
    unique_ptr<T[]> p_;
    unsigned size_;
public:
    Dynarray(unsigned size)
        : p_{make_unique<T[]>(size)}, size_{size}
    {}

    auto operator[](unsigned idx) -> T& { return p_[idx]; }
    auto size() -> unsigned { return size_; }

    auto begin() -> T* {return &p_[0]; }
    auto end() -> T* { return &p_[size_]; }
};

template<typename T>
class Vector {
    unique_ptr<T[]> p_{nullptr};
    unsigned storaged_{0};
    unsigned capacity_{0};
public:
    Vector()=default;

    auto push_back(T const& value) -> void {
        if (storaged_==capacity_){//primera vez que invocamos a la funcion o nos hemos quedado sin capacidad
            auto new_capacity = (capacity_ ==0)? 2 : capacity_*2;//si capacity igual a 0 la hacemos dos, si no la duplicamos
            //reservamos un nuevo bloque de memoria con la capacidad:
            auto new_block = make_unique<T[]>(new_capacity);
            //copiamos el vector referenciado por p_ dentro de new_block
            for (auto i=0u; i<storaged_; ++i){
                new_block[i] = p_[i];
            }
            //new block transfiere la propiedad del nuevo vector a p_
            //y p_ renuncia entonces a la propiedad delvector original, que es destruida
            p_ = std::move(new_block);
            //asignamos la nueva capacidad al vector
            capacity_=new_capacity;
        }
        //situamos una copia del valor pasado como argumento al fondo del vector
        p_[storaged_] = value;
        ++storaged_;
    }

    auto operator[](unsigned idx) -> T& { return p_[idx]; }

    auto size() -> unsigned { return storaged_; }
    auto capacity() -> unsigned { return capacity_; }

};

auto main() -> int {
    //Código previo
    /*cout << "Numero de elementos: ";
    auto n=0u;
    (cin >> n).ignore();

    auto numeros = Dynarray<int>(n);
    auto idx=0;
    for (int& i : numeros){
        cout << fmt::format("Casilla #{}: ", ++idx);
        (cin >> i).ignore();
    }

    for (int i : numeros){
        cout << fmt::format("{}\n", i);
    }*/

    auto numeros = Vector<int>{};
    numeros.push_back(1);
    numeros.push_back(2);
    numeros.push_back(3);

    for (auto i = 0u; i<numeros.size(); ++i){
        cout << numeros[i] << '\n';
    }

    return EXIT_SUCCESS;
}