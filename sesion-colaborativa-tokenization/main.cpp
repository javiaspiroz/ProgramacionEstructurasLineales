#include <cctype> //contiene std::tolower
#include <cstdlib>
#include <fmt/format.h>
#include <fstream> //necesario para emplear file_to_string
#include <functional>
#include <iostream>
#include <map>
#include <range/v3/action/transform.hpp> //util para pasar a minusculas
#include <range/v3/algorithm/sort.hpp>
#include <range/v3/view/map.hpp>
#include <range/v3/view/take.hpp> //util para selecccionar las 5 primeras frecuencias
#include <string>
#include <vector>

//Autores: Javier Aspiroz, Sebastian Quinayas, Solange Roman y Javier Perez

using namespace std;
using fmt::format;
using token_t = string; //sobrenombre para el tipo de token
using frequency_t = int; //sobrenombre para el tipo frecuencia

//Siguientes dos funciones dadas por el profesor
template<typename String>
[[nodiscard]] auto file_to_string(String const& filename) -> std::string
{
   auto in = std::ifstream{};
   in.exceptions(std::ifstream::failbit);

   in.open(filename, std::ios::binary);
   auto contents = std::string{};
   in.seekg(0, std::ios::end);
   auto sz = std::streamoff{in.tellg()}; // signed integer
   if (sz > 0) {
      contents.resize(sz); // contiguous since C++11
      in.seekg(0, std::ios::beg);
      in.read(&contents[0], sz);
   }
   return contents;
}

template<typename String = std::string> // std::string_view for non-owning vector
[[nodiscard]] auto split(String const& text, char const* delims) -> std::vector<String>
{
   auto tokens = std::vector<String>{};
   using sz_t = typename String::size_type;
   auto first = sz_t{0};

   while (first < text.size()) {
      auto last = text.find_first_of(delims,first);

      if (first != last)
         tokens.emplace_back(text.substr(first,last - first));

      if (last == String::npos)
         break;

      first = last + 1;
   }
   return tokens;
}

auto main() -> int{
    //cargamos todo el libro en memoria 
    auto const text = file_to_string("D://MisDocumentos//UEM//Proyectos//ProgramacionEstructurasLineales//sesion-colaborativa-tokenization//4300-0.txt");

    //diccionario token -> frecuencia (inicialmente vacia)
    auto token_freq_dict = map<token_t, frequency_t>{};

    //visitamos el texto palabra por palabra
    for (auto& tkn : split(text, " .,;\r\n!?()[]{}\"")){
        //pasamos el token a minusculas
        tkn |= ranges::action::transform([](char c){ return tolower(c); });
        ++token_freq_dict[tkn];//actualizamos la frecuencia de la palabra en el diccionario
    }
    
    //diccionario donde las keys son las frecuencias y se van anadiendo de mayor a menor
    auto freq_tokens_dict = map<int, vector<string>, greater<> >{};
    for (auto& [tk, f] : token_freq_dict){
        //metemos la frequencia en el diccionario y el numero de palabras asociadas
        freq_tokens_dict[f].push_back(tk);
    }

    for (auto [f, tk] : freq_tokens_dict | ranges::view::take(5)){
        for (string cadena : tk){//imprimimos los 5 primeros por pantalla
            cout << cadena << " " << f << "\n";
        }
    }

    auto csv_file = fstream{"results.csv", ios::out | ios::binary};
    auto ranking=0;
    for(auto [f, tk] : freq_tokens_dict){//pasamos todas las frecuencias a un archivo csv
        for (string cadena : tk){
            csv_file << ++ranking << ", " << f << "\n";
        }
    }

    return EXIT_SUCCESS;
}