// Copyright 2019 DiamNet Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include <cstdint>
#include <functional>
#include <memory>

namespace DiamNet
{
class Application;
class Config;
class Bucket;
}

namespace BucketTests
{
uint32_t getAppLedgerVersion(DiamNet::Application& app);

uint32_t getAppLedgerVersion(std::shared_ptr<DiamNet::Application> app);
void for_versions_with_differing_bucket_logic(
    DiamNet::Config const& cfg,
    std::function<void(DiamNet::Config const&)> const& f);

struct EntryCounts
{
    size_t nMeta{0};
    size_t nInit{0};
    size_t nLive{0};
    size_t nDead{0};
    size_t
    sum() const
    {
        return nLive + nInit + nDead;
    }
    size_t
    sumIncludingMeta() const
    {
        return nLive + nInit + nDead + nMeta;
    }
    EntryCounts(std::shared_ptr<DiamNet::Bucket> bucket);
};

size_t countEntries(std::shared_ptr<DiamNet::Bucket> bucket);
}
