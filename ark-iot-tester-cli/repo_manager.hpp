#ifndef REPO_MANAGER_HPP
#define REPO_MANAGER_HPP

#include <vector>
#include <string>
#include <cstdlib>
#include <map>

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

#include "types.hpp"
#include "utils.hpp"

namespace Ark {
namespace IoT {
namespace Tester {

class repo_manager {
private:
    static const std::map<supported_repos, std::string> github_map;
    static const fs::path base_temp_dir;
    const fs::path working_dir;

public:
    repo_manager() : working_dir(base_temp_dir / fs::path("ark-iot-test")) {
        cleanup();

        if (!fs::create_directories(working_dir)) {
            throw std::runtime_error("Unable to create working directory");
        }
    }

    ~repo_manager() {
        cleanup();
    }

    void clone_repo(supported_repos repo) {
        std::ostringstream clone_cmd;
        clone_cmd << "git clone " << github_map.at(repo) << ' ' << working_dir.string();
        const auto output = exec(clone_cmd.str());
        //TODO: validate good clone
    }

    std::vector<std::string> get_available_test_items(supported_test_types test_type) {
        std::ostringstream fetch_cmd;
        // get the branches
        fetch_cmd << "cd " << working_dir << " && git pull --all";
        auto output = exec(fetch_cmd.str());
        //TODO:  validate good branch pull

        fetch_cmd = std::ostringstream();
        // get the PRs
        fetch_cmd << "cd " << working_dir << " && git fetch origin +refs/pull/*/merge:refs/remotes/origin/pr/*";
        output = exec(fetch_cmd.str());
        //TODO: validate good PR pull

        fetch_cmd = std::ostringstream();
        fetch_cmd << "cd " << working_dir << " && git branch --all";
        output = exec(fetch_cmd.str());
        std::vector<std::string> branches = split(output, '\n');

        for (auto it = branches.begin(); it != branches.end(); ++it) {
            if (it->find("remotes/origin/") == std::string::npos || it->find("remotes/origin/HEAD") != std::string::npos) {
                branches.erase(it--);
            }
        }
        return branches;
    }

    void checkout_test_item(supported_test_types test_type, const std::string& test_item) {
        std::ostringstream checkout_cmd;
        checkout_cmd << "cd " << working_dir << " && git checkout " << test_item;
        const auto output = exec(checkout_cmd.str());
        //TODO: validate good checkout
    }

    void build() {
        std::ostringstream build_cmd;
        build_cmd << "cd " << working_dir << " && pio run";
        const auto output = exec(build_cmd.str());
        //TODO: fix validate good build
        if (output.find("Environment esp8266     [SUCCESS]") == std::string::npos ||
            output.find("Environment esp32       [SUCCESS]") == std::string::npos /*||
            output.find("Environment atmega32p   [SUCCESS]", pos) == std::string::npos ||
            output.find("Environment m4          [SUCCESS]", pos) == std::string::npos*/) {
                throw std::runtime_error("Build Failed");
        }
    }

private:
    void cleanup() {
        if (fs::exists(working_dir)) {
            fs::remove_all(working_dir);
        }
    }
};

}
}
}

#endif
