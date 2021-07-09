#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <list>
#include <range/v3/action/remove_if.hpp>
//#include <stack>

using namespace std;
namespace ra = ranges::action;

template<typename T>
class Stack{
    list<T> lista_;
public:
    Stack()=default;
    //modificadores
    auto push(T const& val) -> void { lista_.push_front(val); }//añade un elemento sobre la cima
    auto pop() -> void { lista_.pop_front(); } //elimina la cima
    auto top() -> T& { return lista_.front(); }
    //capacidad
    auto size() const { return lista_.size(); }
    auto empty() const -> bool { return lista_.empty(); }
};

auto main() -> int {
    //implementacion basica de lista
    auto lista = list<int>{1,2,3,4,5,6};
    //lista.push_back(7);
    //lista.push_front(0);//introducimos 0 al principio de la lista
    //cout << lista.front() << lista.back();//imprimimos primer y ultimo nodo de la lista
    /*for (auto i : lista){//imprimimos la lista
        cout << fmt::format("{} ", i);
    }*/
    //prueba con iteradores
    //list<int>::iterator iter = lista.begin();//hace lo mismo que la siguiente linea
    /*auto iter=lista.begin();//apunta al primer nodo de la lista
    advance(iter, 3);*/
    //  *iter=0;
    /*lista.insert(iter, 7);
    cout << *iter;*/

    //
    //ra::remove_if(lista, [](int i){ return i%2 ==0; });
    /*for (auto iter =lista.begin(); iter!=lista.end(); ++iter){
        if(*iter%2==0)
            lista.erase(iter);
        else
            ++iter;

    }*/

    auto pila = Stack<int>{};//pila vacia
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    cout << pila.size();

    while(!pila.empty()){//mientras la pila no esta vacia
        cout << fmt::format("num: {}\n", pila.top());//leemos la cima
        pila.pop();//quitamos la cima
    }

    return EXIT_SUCCESS;
}