#include "repo_manager.hpp"
#include "types.hpp"

namespace Ark {
namespace IoT {
namespace Tester {

const std::map<supported_repos, std::string> repo_manager::github_map = {
    { supported_repos::Cpp_Client, "https://github.com/ArkEcosystem/cpp-client.git" },
    { supported_repos::Cpp_Crypto, "https://github.com/ArkEcosystem/cpp-crypto.git" }
};

const fs::path repo_manager::base_temp_dir = "/var/tmp";

}
}
}
