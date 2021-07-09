#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

auto main() -> int {
    auto data_path = "D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//actividad_cierre2//code_i.txt";
    auto file = fstream(data_path, ios::in | ios::binary);
    auto pila = stack<char>{};
    
    auto line = string{};
    while (getline(file, line)) {
        for (auto c : line){
        //simbolo terminacion metemos en pila
            if (c=='[' || c=='('){
                pila.push(c);
            }
            //dos siguientes ifs en caso de encontrar un elemento de cierre
            if (!pila.empty() && c==']'){
                if (pila.top()!='['){
                    cout << "Error, codigo no valido, comprueba las expresiones []\n";
                    pila.pop();
                }
            }

            if (!pila.empty() && c==')'){
                if (pila.top()!='('){
                    cout << "Error, codigo no valido, comprueba las expresiones ()\n";
                    pila.pop();
                }
            }

            if (pila.empty() && (c==']' || c==')')){//pila vacia y encontramos simbolo cierre
                cout << "Error, codigo no valido\n";
                pila.pop();
            }
        }        
    }

    //visitamos todo el codigo y pila no vacia
    if (!pila.empty()){
        cout << "Error, codigo no valido, la pila no esta vacia\n";
    }

    return EXIT_SUCCESS;
}