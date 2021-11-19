#ifndef CHLOVER_ENGINE_HASH_HPP
#define CHLOVER_ENGINE_HASH_HPP

#include <string>
#include <array>
#include <chlover/util/Representation.hpp>
#include <memory>

#define CHLOVER_CONTEXT_SIZE 0x3fff
#define CHLOVER_CONTEXT_SIZE_512 (CHLOVER_CONTEXT_SIZE & 512)
#define CHLOVER_CONTEXT_TYPE_OPENSSL (0x1 << 31)
#define CHLOVER_CONTEXT_TYPE_SHA3 (CHLOVER_CONTEXT_TYPE_OPENSSL | 0x3 << 15)

namespace chlover::util::hash {
    typedef std::basic_string_view<unsigned char> Digest;

    class HashContext {
      public:
        virtual void reset() {
            throw std::exception();
        };
        virtual void update(std::basic_string_view<char> data) {
            throw std::exception();
        }
        virtual Digest digest() {
            throw std::exception();
        }
        std::string digest(Representation representation) {
            return represent(digest(), representation);
        }
    };

    std::unique_ptr<HashContext> setupContext(uint64_t type);
}

#endif
