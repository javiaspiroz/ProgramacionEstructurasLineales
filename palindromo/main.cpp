#include <cstdlib>
#include <fmt/format.h>
#include <iostream>
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

auto main() -> int {
    auto pila = stack<char>{};//vacio
    auto cola = queue<char>{};//vacio
    bool es_palindromo = true;//para comprobar si son iguales las dos letras comparadas

    auto palabra = string{};
    cout << "Enter a word: ";
    //cin >> palabra;
    getline(cin, palabra);
    //cout << searched_word << '\n';

    for (char c : palabra){//pasamos los caracteres de la palabra a ambas estructuras
        pila.push(c);
        cola.push(c);
    }

    while (!pila.empty() and es_palindromo){//mientras existan aun caracteres
        if (pila.top() != cola.front()){
            es_palindromo=false;
            continue;
        }
        pila.pop();//eliminamos la cima actual de la pila
        cola.pop(); //eliminamos el frente de la cola
    }

    if (es_palindromo)//imprimimos el resultado
        cout << "Es palindromo";
    else
        cout << "No es palindromo";

    return EXIT_SUCCESS;
}