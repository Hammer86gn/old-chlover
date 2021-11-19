#ifndef CHLOVER_ENGINE_REPRESENTATION_HPP
#define CHLOVER_ENGINE_REPRESENTATION_HPP

#include <string>
namespace chlover::util {
    enum Representation {
        CHLOVER_REPRESENTATION_HEX
    };

    std::string represent(std::basic_string_view<unsigned char> data, Representation representation);
}

#endif
