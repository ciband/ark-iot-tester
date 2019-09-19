#ifndef REPO_MANAGER_HPP
#define REPO_MANAGER_HPP

#include <vector>
#include <string>

#include "types.hpp"

namespace Ark { 
namespace IoT {
namespace Tester {

class repo_manager {
public:
    repo_manager() = default;

    void clone_repo(supported_repos repo) {

    }

    std::vector<std::string> get_available_test_items(supported_test_types test_type) {

    }

    void checkout_test_item(supported_test_types test_type, const std::string& test_item) {

    }

    void build() {
        
    }
};

}
}
}

#endif
