#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>

namespace Ark {
namespace IoT {
namespace Tester {

inline std::string exec(std::string cmd) {
    std::array<char, 128> buffer;
    std::string result;
    cmd += " 2>&1";
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
        std::cout << buffer.data();
    }
    return result;
}

inline std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

}
}
}

#endif
