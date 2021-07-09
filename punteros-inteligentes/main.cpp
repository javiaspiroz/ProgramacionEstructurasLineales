#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include <fmt/format.h>

struct Player
{
    std::string name{};
    int level{0};
};

auto main() -> int {
    //auto p = std::make_shared<Player>(Player{"Terminator", 24});//para que se almacene en el free store
    auto p = std::make_unique<Player>(Player{"Terminator", 24});//p tiene el dominio completo del puntero
    auto q = std::move(p);//transferimos la propiedad del puntero de p a q, p se quedaría en NULL

    if (!p)
        std::cout << "p is empty";

    q->name="John Connor";
    std::cout << q->name;//con flecha ya que es un puntero
    return EXIT_SUCCESS;
}