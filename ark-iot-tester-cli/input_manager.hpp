#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <iostream>
#include <vector>
#include <string>

#include "types.hpp"

namespace Ark {
namespace IoT {
namespace Tester {

class input_manager {
public:
    input_manager() = default;

    supported_repos get_repo_to_test() {
        std::cout << "Welcome to the Ark Ecosystem IoT Tester\n"
                  << "Please select a repository to test:\n\n";

        std::cout << "1: Cpp-Crypto\n"
                  << "2: Cpp-Client\n";

        std::cout << "Enter selection: ";
        int selection;
        std::cin >> selection;
        const auto selected_repo = static_cast<supported_repos>(selection);
        switch (static_cast<supported_repos>(selection)) {
            case supported_repos::Cpp_Crypto:
            case supported_repos::Cpp_Client:
                return selected_repo;

            default:
                throw std::runtime_error("Invalid repo selected");
        }
    }

    supported_test_types should_test_branch_or_pr() {
        std::cout << "What would you like to test?\n";

        std::cout << "1: Branch\n"
                  << "2: Pull Request\n\n";

        std::cout << "Enter selection: ";
        int selection;
        std::cin >> selection;
        const auto selected_test_type = static_cast<supported_test_types>(selection);
        switch (static_cast<supported_test_types>(selection)) {
            case supported_test_types::branch:
            case supported_test_types::pr:
                return selected_test_type;

            default:
                throw std::runtime_error("Invalid test item selected");
        }
    }

    std::string get_branch_or_pr_to_test(supported_test_types test_type, const std::vector<std::string>& test_item_list) {
        std::cout << "which " << to_string(test_type) << " would you like to test?\n";

        auto i = 1;
        for (const auto& item : test_item_list) {
            std::cout << i++ << ": " << item << '\n';
        }
        std::cout << '\n';

        std::cout << "Enter selection: ";
        std::cin >> i;

        if (i >= test_item_list.size()) {
            throw std::runtime_error("Invalid index into branch/pr list");
        }
        return test_item_list[i];
    }
};

}
}
}

#endif
