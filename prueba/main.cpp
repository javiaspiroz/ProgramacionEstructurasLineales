#include <iostream>
#include <cstdlib>

auto main() -> int{
    double a=3, c=3; 
    double b = 3/(a-c);
    std::cout << b;
    if (b==b){
        std::cout << "Not Infinity";
    }
    else{
        std::cout << "Infinity";
    }

    return EXIT_SUCCESS;
}