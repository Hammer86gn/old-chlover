#include <chlover/util/Hash.hpp>
#include <openssl/sha.h>
#include <openssl/evp.h>

class OpenSSLContext : public chlover::util::hash::HashContext {
  private:
    EVP_MD_CTX* context = nullptr;
    const EVP_MD* md = nullptr;
    size_t length;

  public:
    OpenSSLContext(const EVP_MD* md, size_t lengthBytes) {
        this->md = md;
        this->length = lengthBytes;
        this->reset();
    }
    ~OpenSSLContext() {
        if (context != nullptr) {
            EVP_MD_CTX_free(context);
        }
    }

    void reset() final {
        if (context != nullptr) {
            EVP_MD_CTX_free(context);
        }
        context = EVP_MD_CTX_new();
        EVP_DigestInit_ex(context, md, nullptr);
    }

    void update(std::basic_string_view<char> data) final {
        EVP_DigestUpdate(context, data.data(), data.size());
    }
    chlover::util::hash::Digest digest() final {
        unsigned char data[length];
        uint32_t writtenLength;
        EVP_DigestFinal_ex(context, data, &writtenLength);
        return {data, writtenLength};
    }

};

std::unique_ptr<chlover::util::hash::HashContext> chlover::util::hash::setupContext(uint64_t type) {
    if (type & CHLOVER_CONTEXT_TYPE_OPENSSL) {
        const EVP_MD* md;
        size_t length;
        if (type & CHLOVER_CONTEXT_TYPE_SHA3) {
            switch (type & CHLOVER_CONTEXT_SIZE) {
                case 256:
                    md = EVP_sha3_256();
                    length = 32;
                    break;
                case 512:
                    md = EVP_sha3_512();
                    length = 64;
                    break;
            }
        }
        return std::make_unique<OpenSSLContext>(md, length);
    }
    return nullptr;
}
