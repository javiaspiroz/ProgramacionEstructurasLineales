#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

template<typename T>
class Queue{
    list<T> lst_;
public:
    Queue()=default;//queue vacio

    //capacidad
    auto empty() const -> bool { return lst_.empty(); }
    auto size() const /*-> list<T>::size_type*/ {return lst_.size(); }

    //acceso y modificacion
    auto push (T const& val) -> void { lst_.push_back(val); }//insertamos val al final de la cola
    auto pop() -> void { lst_.pop_front(); }

    auto front() -> T& { return lst_.front(); }
    auto back() -> void { return lst_.back(); }
};

auto main() -> int {
    auto q=Queue<int>{};
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (q.empty()){
        cout << q.front() << '\n';
        q.pop();
    }

    return EXIT_SUCCESS;
}