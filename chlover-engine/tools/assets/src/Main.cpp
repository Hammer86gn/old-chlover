#include <chlover/assets/Asset.hpp>
#include <argh.h>

int main(int argc, char** argv) {
    argh::parser parser{};
    parser.add_params({"", " "});
    parser.parse(argc, argv);

    std::string command = parser[0];


}