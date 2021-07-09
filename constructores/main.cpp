#include <cstdlib>
#include <iostream>
#include <string>
#include <fmt/format.h>
#include <memory>

struct Player{
        std::string name{};
        std::string password{};
        //Player(std::string s){//constructor que me dice cuando nace un jugador
            //name=s;
            //std::cout << fmt::format("hola jugador {}\n",name);
        //}
        ~Player(){//destructor que me dice cuando uere un objeto
            std::cout << fmt::format("adiós jugador {}\n",name);
        }
    };

auto main() -> int{
    
    auto datos = std::array<Player, 3>{};

    //pedimos al usuario que introduzca los datos
    for (auto i=0u; i<datos.size(); ++i){//size es unsigned pero poner u a i lo soluciona
        std::cout <<"Name: ";
        std::getline(std::cin, datos[i].name);
        std::cout <<"Password: ";
        std::getline(std::cin, datos[i].password);        
    }
    for (Player const& p : datos){//otra forma de ponerlo: auto i=0u; i<datos.size();++i
        std::cout << fmt::format("Name: {} | Password: {}\n", p.name, p.password);
    }

    return EXIT_SUCCESS;
}