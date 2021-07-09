#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <memory>
#include <string>

struct Dinosaur {//interfaz, usamos polimorfismo dinámico
    virtual auto attack() const -> void =0;//void=0 implica que es un método puro
                                        //con virtual definimos que es una clase virtual
    virtual ~Dinosaur() = default;//destructor virtual
};

struct Brachio : Dinosaur{//indicamos brachio que es una clase descendiente de dinosaur
    auto attack() const -> void 
    override {//para aclarar que viene de una clase abstracta
        std::cout << "brachiosaurus\n";
    }
};

struct Raptor : Dinosaur{
    auto attack() const -> void
    override {std::cout << "velociraptor\n"; }
};

struct Trex : Dinosaur{
    auto attack() const -> void override {std::cout << "tyrannosaurus rex\n"; }
};

auto main() -> int {
    auto level = int{-1};
    while(level<0 or level >2){
        std::cout << "Nivel de ataque [0, 1, 2]: ";
        std::cin >> level;
    }
    auto d = std::unique_ptr<Dinosaur>();
    switch (level){
    case 0:
        d = std::make_unique<Brachio>();
        break;    
    case 1: d = std::make_unique<Raptor>(); break;    
    case 2: d = std::make_unique<Trex>(); break;
    default: return EXIT_FAILURE;//aunque no haría falta, ya que comprobamos los valores antes
    }
    std::cout << "En ataque: ";
    d->attack();
    return EXIT_SUCCESS;
}