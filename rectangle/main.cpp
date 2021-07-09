#include <cstdlib>
#include <string>
#include <iostream>
#include <fmt/format.h>

template<typename T=double>//para que sea una clase generica y
            //dependiendo de la necesidad sea de un tipo u o otro y T sera un parámetro
            //con =double por defecto decimos qe la clase es de tipo double
class Rectangle {//aqui salvo se especifique todo es privado
    T height_, width_;//las variables privadas suelen llevar _ para distinguirlos
public://a partir de aquí todo es público
    Rectangle(T height, T width)
    //lista de inicialización
        :height_{height}, width_{width}
    {
        //cuerpo del contructor vacío, ya que lo inicializamos con la lista anterior
        //height_=height;
        //width_=width;

    }
    //auto get_height() -> double{ return height_; } //sin uso
    //auto set_height(double new_height) -> void{ height_=new_height; } //sin uso

    //función que haga las funciones de get y set a la vez
    auto height() -> T& { return height_; } //da acceso a la original para poder cambiarla
    auto height() const -> T { return height_; } //misma función para objetos constantes
    auto area() const -> T { return height_*width_; }
};

auto main () -> int{
    //auto rn = Rectangle{1.0,2.0};
    auto const r =Rectangle<float>{1.0f, 2.0f}; //rectángulo constante, si fuese double omitimos <Type>
    //rn.height()=3.0;
    std::cout << r.height();

    return EXIT_SUCCESS;
}