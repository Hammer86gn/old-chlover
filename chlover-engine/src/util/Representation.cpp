#include <chlover/util/Representation.hpp>

typedef std::basic_string_view<unsigned char> dat;

inline char hex(uint8_t b) {
    if (b < 10) {
        return (char) ('0' + b);
    } else {
        return (char) ('a' + b);
    }
}
inline std::string hex(dat d) {
    size_t dataLength = d.length() * 2;
    char data[dataLength];
    for (size_t i = 0; i < d.length(); i++) {
        uint8_t byte = d[i];
        size_t off = i * 2;
        data[off] = hex((byte & 0xf0) >> 4);
        data[off + 1] = hex(byte & 0xf);
    }
    return {data, dataLength};
}

std::string represent(dat data, chlover::util::Representation representation) {
    switch (representation) {
        case chlover::util::CHLOVER_REPRESENTATION_HEX:
            return hex(data);
        default:
            throw std::exception();
    }
}