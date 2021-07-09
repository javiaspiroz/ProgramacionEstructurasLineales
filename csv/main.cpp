#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

template<typename T1, typename... Args>//indicando un numero indefinido de parametros
auto sep_println(fstream& f, T1 const& arg1, Args const&... args) -> void{
    //f << s << ',' << a << ',' << i << '\n';
    
    f << arg1;
    auto operation = [&f](auto const& arg) {f << ',' << arg; };
    (..., operation(args)); //fold expression
    f << '\n';
}

auto main() -> int{
    auto csv_file = fstream{"data.csv", ios::out | ios::binary};
    sep_println(csv_file, string{"hello!"}, 8.99, 7, 'a', string{" world!"});

    return EXIT_SUCCESS;
}