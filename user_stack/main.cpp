#include <cstdlib>
#include <iostream>
#include <string>
#include <fmt/format.h>

struct S {
    int i; //contador
    S(int i_) {
        i=i_;
        std::cout << fmt::format("creating {}\n", i);//constructor
    }
    ~S() {std::cout << fmt::format("destroying {}\n", i); }//destructor
};

auto f() -> void {
    auto s3=S{3};
    auto s4=S{4};
}

auto main() -> int {
    auto s1 =S{1};
    auto s2 = S{2};
    f();//invoco funcion f()

    return EXIT_SUCCESS;
}