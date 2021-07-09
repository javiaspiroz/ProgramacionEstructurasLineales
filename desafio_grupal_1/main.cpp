#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <vector>

#include "match.hpp"
#include "read_cin.hpp"//Incluida para la entrada de datos segura por terminal

using namespace std;
using namespace fmt;

struct Point {
    double x, y;//Coordenadas del punto
};

struct Line {
    Point p1, p2;
    auto slope() const -> double { return (p2.y-p1.y)/(p2.x-p1.x); }//Calculamos la pendiente m
    //Usando la recta y=mx+b, ahora calculamos la b que es el termino independiente
    auto b() const -> double { return p1.y-(slope()*p1.x); }
};

struct Infinity {};//Estructura vacia usada en el caso de que las rectas sean paralelas

auto create_lines() -> vector<Line>{
    auto lines=vector<Line>{};//Vector que almacenara las rectas

    //Pedimos al usuario que meta los puntos de las lineas
    auto palabra = string{};
    auto line_aux=Line{};
    do{
        cout << "Introduce la x del primer punto: ";
        mcpp::read_cin(line_aux.p1.x);
        cout << "Introduce la y del primer punto: ";
        mcpp::read_cin(line_aux.p1.y);
        do{
            cout << "Introduce la x del segundo punto, recuerda que este punto debe ser diferente al primero: ";
            mcpp::read_cin(line_aux.p2.x);
            cout << "Introduce la y del segundo punto, recuerda que este punto debe ser diferente al primero: ";
            mcpp::read_cin(line_aux.p2.y);
        }//Compruebo que los dos puntos introducidos no sean iguales y si lo hago meter otros
        while(line_aux.p1.x==line_aux.p2.x and line_aux.p1.y==line_aux.p2.y);
        lines.push_back(line_aux);
        cout << "Si quieres meter una recta mas aprieta cualquier tecla, si no escribe 'stop': ";
    }while (mcpp::read_cin(palabra, "stop"));
    return lines;
}

auto print_lines(vector<Line> const& lines)  -> void{
    int k=1;
    for (auto l : lines){//Imprimimos las lineas obtenidas
        cout << format("Recta {}: ({},{}); ({},{}) -> Pendiente {} y Ordenada en el Origen {}\n", k, l.p1.x, l.p1.y, l.p2.x, l.p2.y, l.slope(), l.b());
        ++k;
    }
}

using Intersect_result = variant<Point, Line, Infinity>;//Define los tipos de resultados que podemos tener

auto results (Line l1, Line l2) -> Intersect_result{
    if(l1.p1.x==l1.p2.x and l2.p1.x==l2.p2.x){//Caso de rectas verticales siendo l1 y l2 verticales
        if (l1.p1.x==l2.p1.x and l1.p1.x==l2.p2.x and l1.p2.x==l2.p1.x and l1.p2.x==l2.p2.x){//Coincidentes
            return l1;//devuelvo una de las dos rectas ya que son la misma
        }
        else{//Paralelas, no pueden ser secantes si las dos rectas son verticales
            auto void_infinity = Infinity{};
            return void_infinity;
        }
    }
    else if (l1.p1.x==l1.p2.x){//Caso de rectas verticales, siendo l1 vertical y l2 no
        auto y = (l2.slope()*l1.p1.x)+l2.b();
        Point intersection = Point{l1.p1.x, y};
        return intersection;
    }
    else if (l2.p1.x==l2.p2.x){//Caso de rectas verticales, siendo l2 vertical y l1 no
        auto y = (l1.slope()*l2.p1.x)+l1.b();
        Point intersection = Point{l2.p1.x, y};
        return intersection;
    }
    //A partir de aqui valen para todas las rectas que no sean verticales
    else if (l1.slope()==l2.slope() and l1.b()==l2.b()){//Caso de coincidentes
        return l1;//devuelvo una de las dos rectas ya que son la misma        
    }
    else if(l1.slope()==l2.slope() and l1.b()!=l2.b()){//Caso de paralelas
        auto void_infinity = Infinity{};
        return void_infinity;
    }
    else{//Para las rectas secantes
        auto x = (l2.b()-l1.b())/(l1.slope()-l2.slope());
        auto y = (l1.slope()*x)+l1.b();
        Point intersection = Point{x, y};
        return intersection;
    }
}

auto print (Intersect_result const& result) -> void{//Imprimimos el resultado de la recta
    mcpp::match(result,
        [](Point p) { cout << format("secantes e intersectan en el punto ({},{})\n", p.x, p.y); },//Secantes
        [](Line l) { cout << format("coincidentes y tienen pendiente {} y la ordenada en el origen {}\n",l.slope(), l.b()); },//Coincidentes
        [](Infinity) { cout << "paralelas\n"; }//Paralelas
    );
}

auto main() -> int {
    auto lines=create_lines();//Vector que almacenara las rectas

    print_lines(lines);//Imprimimos todas las rectas

    //Comprobamos las relaciones entre rectas
    unsigned j=1u;//Contadores de las rectas
    for (auto i=0u; i<lines.size()-1; ++i){
        for (; j<lines.size(); ++j){
            if (j!=i){
            auto result=results(lines[i],lines[j]);
            cout << format("Las rectas {} y {} son ",i+1, j+1);
            print(result);
            }
        }
        j=i+1;      
    }

    return EXIT_SUCCESS;
}