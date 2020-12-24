// Copyright 2017 DiamNet Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include "test/TestPrinter.h"
#include "lib/util/format.h"
#include "test/TestMarket.h"

namespace Catch
{
std::string
StringMaker<DiamNet::OfferState>::convert(DiamNet::OfferState const& os)
{
    return fmt::format(
        "selling: {}, buying: {}, price: {}, amount: {}, type: {}",
        xdr::xdr_to_string(os.selling), xdr::xdr_to_string(os.buying),
        xdr::xdr_to_string(os.price), os.amount,
        os.type == DiamNet::OfferType::PASSIVE ? "passive" : "active");
}

std::string
StringMaker<DiamNet::CatchupRange>::convert(DiamNet::CatchupRange const& cr)
{
    return fmt::format("[{}..{}], applyBuckets: {}", cr.mLedgers.mFirst,
                       cr.getLast(), cr.getBucketApplyLedger());
}

std::string
StringMaker<DiamNet::historytestutils::CatchupPerformedWork>::convert(
    DiamNet::historytestutils::CatchupPerformedWork const& cm)
{
    return fmt::format("{}, {}, {}, {}, {}, {}, {}, {}",
                       cm.mHistoryArchiveStatesDownloaded,
                       cm.mLedgersDownloaded, cm.mLedgersVerified,
                       cm.mLedgerChainsVerificationFailed,
                       cm.mBucketsDownloaded, cm.mBucketsApplied,
                       cm.mTransactionsDownloaded, cm.mTransactionsApplied);
}
}
