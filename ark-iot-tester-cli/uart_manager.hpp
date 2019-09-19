#ifndef UART_MANAGER_HPP
#define UART_MANAGER_HPP

namespace Ark { 
namespace IoT {
namespace Tester {

class uart_manager {
public:
    uart_manager() {
        connect();
    }

    ~uart_manager() {
        close();
    }

    void connect() {

    }

    void close() {

    }

    void upload_to_mcus() {

    }

    std::string read_mcu_output() {
        
    }
};

}
}
}

#endif
