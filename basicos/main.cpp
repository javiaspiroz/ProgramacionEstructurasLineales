#include <cstdlib>
#include <iostream>
#include <string>
#include <fmt/format.h>
#include <memory>//para trabajar con el free store

//definimos funcion incrementa 4
auto incrementa_cuatro(int& j) -> void {j+=4; }//sin & se hace una copia y nomodifica la i, ahora sí lo cambia

struct Player {
    std::string name{};
    int level{0};
};

auto increase_level (Player& q){//funcion no valida con shared, abria que modificarla
    ++q.level;
}

auto main()-> int {
   // auto i = int{10}; //auto i = 10 tambien sería interpretado solo como int, 
                //double i=10.0, float 10.0f, unsigned 10u, 
                //definimos const para que no pueda ser cambiado el valor de una variable
   // auto& j = i;//j es una referencia (copia) de i y replican sus acciones
    
    auto p = std::make_shared<Player>(Player{"Sarah Connor", 25}); //tambien se puede poner el new,
                                                // lo modificamos para que sea almacane en en el free store
                                                //y hacer una referencia
    std::cout << fmt::format("contador: {}\n", p.use_count()); //contar el numero de referencias al objeto
    {//dentro de este ambito (bloque)es donde se puede usar q fuera no
        auto q =p ; //q es una copia de P
        q->name = "Teniente Ripley";
        std::cout << fmt::format("contador: {}\n", p.use_count());
    }

    //q.name = "Sara Gomez"; estas operaciones no se pueden hacer así al meterlos en el free store
    //increase_level(p); 

    std::cout << fmt::format("contador: {}\n", p.use_count());
    std::cout << fmt::format("nombre: {}, nivel: {}", p->name, p->level); //con la flecha hacemos la referencia
   
    return EXIT_SUCCESS;
}