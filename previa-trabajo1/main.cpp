#include <iostream>
#include <fmt/format.h>
#include <cstdlib>
#include <cmath>
#include <complex>

#include "match.hpp"

using namespace std;
using namespace fmt;

// ax^2 +bx + c =0 -> (-b +/- sqrt(b^2 - 4ac))/2a

struct Quadratic {
    double a{}, b{}, c{};
    auto operator()(double x) const -> double { return a*pow(x, 2) + b*x + c; }
    auto discriminant() const -> double {return pow(b,2) - 4 *a*c; }
};
//pattern matching
//declaramos esto para saber la formas de que nos puede retornar la función de calculo de raices
using Root_var=variant< double, //raiz real de multiplicidad dos 
                        pair<double,double>,//raices reales distintas
                        pair<complex<double>, complex<double>> >;//complejos

auto compute_roots (Quadratic const& p) -> Root_var {
    auto d=p.discriminant();
    if (d> 0.0){ //dos raíces reales distintas
        auto s =sqrt(d);
        return pair {(-p.b + s)/(2+p.a), (-p.b -s)/(2*p.a)};
    }
    if (d==0.0){//raiz real repetida
        return -p.b/(2*p.a);
    }
    else{//raices complejas
        auto s = sqrt(abs(d));
        return pair{complex{-p.b/(2*p.a), s/2*p.a}, complex{-p.b/(2*p.a), -s/2*p.a}};
    }
}

auto print_roots(Root_var const& roots) -> void {
    mcpp::match(roots,
        [](double r) {cout << format("double real root: {:.2f},", r); },//{:.2f} es para poner solo dos decimales
        [](pair<double, double> rs){
            auto [r1, r2]=rs;
            cout << format("distint real roots: {:.2f}, {:.2f}", r1, r2);
        },
        [](pair<complex<double>, complex<double>> rs){
            auto [r1, r2]=rs;
            cout << format("complex roots: {:.2f} + ({:.2f})i, {:.2f} + ({:.2f})i",
                    r1.real(), r1.imag(), r2.real(), r2.imag());
        }
    );
}

auto main() -> int{
    auto a=double{},b=double{},c=double{};
    cout << "Coefficients a, b and c [ax^2 +bx + c]: ";
    cin >> a >> b >> c;

    auto q = Quadratic{a, b, c};
    auto roots = compute_roots(q);
    print_roots(roots);

    return EXIT_SUCCESS;
}