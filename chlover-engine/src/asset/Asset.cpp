#include <chlover/assets/Asset.hpp>
#include <memory>
#include <chlover/util/Hash.hpp>
static std::unique_ptr<chlover::util::hash::HashContext> ASSET_DIGEST = chlover::util::hash::setupContext(CHLOVER_CONTEXT_TYPE_SHA3 | CHLOVER_CONTEXT_SIZE_512);
chlover::assets::AssetID chlover::assets::getAssetID(std::string data) {
    ASSET_DIGEST->reset();
    ASSET_DIGEST->update(data);
    return ASSET_DIGEST->digest(util::CHLOVER_REPRESENTATION_HEX); // TODO(tecc): Asset IDs - essentially just hashes, prob gonna use SHA512
}
