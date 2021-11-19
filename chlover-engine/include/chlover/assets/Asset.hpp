#ifndef CHLOVER_ENGINE_ASSET_HPP
#define CHLOVER_ENGINE_ASSET_HPP

#include <cstdint>
#include <array>
#include <string>

namespace chlover::assets {
    typedef std::string AssetID;

    AssetID getAssetID(std::string name);

    struct Asset {
      public:
        AssetID getId();
        std::string getName();
    };
}

#endif
