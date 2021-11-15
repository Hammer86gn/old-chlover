#ifndef CHLOVER_ASSET_HPP
#define CHLOVER_ASSET_HPP

#include <cstdint>
#include <array>
#include <string>

namespace chlover::assets {
    typedef std::array<uint8_t, 16> AssetID;

    AssetID getAssetID(std::string name);

    struct Asset {
      public:
        AssetID getId();
        std::string getName();
    };
}

#endif
