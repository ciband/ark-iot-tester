#include <iostream>
#include <vector>
#include <string>

#include "types.hpp"
#include "input_manager.hpp"
#include "repo_manager.hpp"
#include "io_manager.hpp"

using namespace Ark::IoT::Tester;

void print_test_results(supported_platforms platform, bool tests_passed, const std::string& test_output) {
    if (tests_passed) {
        std::cout << to_string(platform) << " tests passed!!!!\n";
    } else {
        std::cout << to_string(platform) << " tests failed. See log:\n";
        std::cout << test_output << "\n\n";
    }
}

int main(int argc, char* argv[]) try {
    input_manager input;
    repo_manager repo;

    const auto selected_repo = input.get_repo_to_test();

    repo.clone_repo(selected_repo);

    const auto test_type = input.should_test_branch_or_pr();
    const auto test_item_list = repo.get_available_test_items(test_type);

    const auto test_item = input.get_branch_or_pr_to_test(test_type, test_item_list);
    repo.checkout_test_item(test_type, test_item);
    repo.build();

    //io_manager io;
    //std::string test_output;

    //auto tests_passed = io.run_test(supported_platforms::esp8266, test_output);
    //print_test_results(supported_platforms::esp8266, tests_passed, test_output);

    //tests_passed = io.run_test(supported_platforms::esp32, test_output);
    //print_test_results(supported_platforms::esp32, tests_passed, test_output);

    //tests_passed = io.run_test(supported_platforms::atmega328p, test_output);
    //print_test_results(supported_platforms::atmega328p, tests_passed, test_output);

    //tests_passed = io.run_test(supported_platforms::m4, test_output);
    //print_test_results(supported_platforms::m4, tests_passed, test_output);

    std::cout << std::endl;
    return 0;
} catch (const std::exception& ex) {
    std::cout << "Error: " << ex.what() << std::endl;
    return 1;
}
