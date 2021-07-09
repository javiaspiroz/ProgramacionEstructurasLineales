#include <cmath>
#include <chrono>
#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

auto factorial(int n) -> int{
    if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}

auto fibonacci(int n)->int{
    //no eficiente para numeros grandes
    /*if(n==0) return 0;
    if (n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);*/

    //usando la formula de binet
    auto const sqrt_5 = sqrt(5);
    return static_cast<int>((pow(1+sqrt_5, n) - pow(1-sqrt_5, n))/(sqrt_5*pow(2,n)));
}

//metaprogramacion: con las plantillas conseguimos hacerlo de la forma mas eficiente posible
template<typename T>
auto sum(T a, T b) -> T{
    return a+b;
}

template<int I>
struct Fib {
    static int const val = Fib<I - 1>::val + Fib<I - 2>::val;
};

template<>//caso base para 0
struct Fib<0> {
    static int const val = 0;
};

template<>//caso base para 1
struct Fib<1> {
    static int const val = 1;
};

auto main() -> int{
    //cout << factorial(3) << '\n';
    auto const start = high_resolution_clock::now();
    auto const f = Fib<45>::val;
    auto const stop = high_resolution_clock::now();
    cout << fmt::format("Fib: {}, Time: {}\n", f, duration_cast<microseconds>(stop-start).count());

    //cout << sum(1, 2) << '\n' << sum(6.2, 7.89) << '\n' << sum(string{"hello"}, string{" world!"}) << '\n';

    return EXIT_SUCCESS;
}