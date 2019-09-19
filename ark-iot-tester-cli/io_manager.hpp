#ifndef IO_MANAGER_HPP
#define IO_MANAGER_HPP

#include "types.hpp"
#include "uart_manager.hpp"

namespace Ark { 
namespace IoT {
namespace Tester {

class io_manager {
public:
    io_manager() = default;

    bool run_test(supported_platforms platform, std::string& test_output) {
        select_platform(platform);

        uart_manager uart;
        uart.upload_to_mcus();

        reset_platform();

        test_output = uart.read_mcu_output();

        return did_tests_pass(test_output);
    }

private:
    void select_platform(supported_platforms platform) {

    }

    void reset_platform() {

    }

    bool did_tests_pass(const std::string& test_output) {

    }
}; 

}
}
}

#endif
