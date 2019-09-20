#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdint>
#include <type_traits>

namespace Ark { 
namespace IoT {
namespace Tester {

enum class supported_repos : uint8_t {
    Cpp_Crypto = 1,
    Cpp_Client = 2
};

typedef std::underlying_type<supported_repos>::type supported_repos_int_type;

inline const char* const to_string(supported_repos repo) {
    switch(repo) {
        case supported_repos::Cpp_Crypto: return "cpp-client";
        case supported_repos::Cpp_Client: return "cpp-crypto";
        default: throw std::runtime_error("to_string - Invalid repo given");
    }
}

enum class supported_test_types : uint8_t {
    branch,
    pr
};

typedef std::underlying_type<supported_test_types>::type supported_test_types_int_type;

inline const char* const to_string(supported_test_types test_type) {
    switch(test_type) {
        case supported_test_types::branch: return "branch";
        case supported_test_types::pr: return "pull request";
        default: throw std::runtime_error("to_string - Invalid test_type given");
    }
}

enum class supported_platforms : uint8_t {
    esp8266,
    esp32,
    atmega328p,
    m4
};

typedef std::underlying_type<supported_platforms>::type supported_platforms_int_type;

inline const char* const to_string(supported_platforms platform) {
    switch(platform) {
        case supported_platforms::esp8266: return "ESP8266";
        case supported_platforms::esp32: return "ESP32";
        case supported_platforms::atmega328p: return "ATMEGA328P";
        case supported_platforms::m4: return "M4";
        default: throw std::runtime_error("to_string - Invalid platform given");
    }
}

}
}
}

#endif
