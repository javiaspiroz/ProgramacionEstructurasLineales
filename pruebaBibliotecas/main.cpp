#include <fmt/format.h>
#include <range/v3/algorithm/sort.hpp>

#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

auto main() -> int
try {
   auto bands = std::map<std::string, std::vector<std::string>>{};

   bands["The Beatles"] = {
      "Paul McCartney",
      "John Lennon",
      "Ringo Starr",
      "George Harrison"
   };
   bands["Pink Floyd"] = {
      "Nick Mason",
      "Syd Barrett",
      "Roger Waters",
      "Richard Wright",
      "David Gilmour",
      "Bob Klose"
   };
   bands["Arctic Monkeys"] = {
      "Alex Turner",
      "Matt Helders",
      "Jamie Cook",
      "Nick O'Malley",
      "Andy Nicholson",
      "Glyn Jones"
   };

   std::cout << "Search a pop/rock band: ";
   auto band_to_search = std::string{};
   std::getline(std::cin, band_to_search);

   if (auto const iter = bands.find(band_to_search); iter != bands.end()) {
      auto& list = bands[band_to_search];
      std::cout << fmt::format("{:_^20}\n", band_to_search);
      ranges::sort(list);
      for (auto const& member : list)
         std::cout << fmt::format("{}\n", member);
   }
   else {
      std::cout << fmt::format("Sorry, '{}' is not on the list", band_to_search);
   }

   return EXIT_SUCCESS;
}
catch (std::exception const& e) {
   std::cerr << e.what();
   return EXIT_FAILURE;
}