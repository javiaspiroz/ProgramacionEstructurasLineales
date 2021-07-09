/*
    MCPP LIBRARIES - read_cin.hpp
    License: GPLv3 - https://www.gnu.org/licenses/gpl-3.0.html
    Author: Daniel G Vergel | daniel.gomez[at]universidadeuropea.es
    Last update: Oct 18, 2019
*/

#ifndef MCPP_LIBRARIES_READ_CIN_HPP
#define MCPP_LIBRARIES_READ_CIN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

namespace mcpp {

    template<typename T> 
    auto read_cin(T& dat, std::string_view sentinel = "<end>") -> bool 
    { 
        for (auto input = std::string{}; std::getline(std::cin, input) and input != sentinel; ) { 
            auto c = char{}; 
            auto strm = std::stringstream{input}; 
            if (strm >> dat and !(strm >> c))
                return true; 
            else
                std::cout << "\a--->[invalid input] try again: "; 
        } 
        return false; 
    }

    enum class string_policy : bool { maybe_empty, never_empty }; 
    
    template<string_policy policy = string_policy::never_empty> 
    auto read_cin(std::string& str, std::string_view sentinel = "<end>") -> bool 
    {  
        if constexpr (policy == string_policy::never_empty) {
            while (std::getline(std::cin, str) and str != sentinel) { 
                if (!str.empty())
                    return true;
                else
                    std::cout << "\a--->[invalid empty string] try again: ";
            }
            return false;
        }
        else // maybe_empty
            return std::getline(std::cin, str) and str != sentinel;
    }

} // NAMESPACE mcpp

#endif // MCPP_LIBRARIES_READ_CIN_HPP