// Copyright (c) 2009-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?label=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.label == QString("Some Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=100&label=Some Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("amero://AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?message=Some Example Address", &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?req-message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=1,000&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=1,000.0&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=100&label=Some Example&message=Some Example Message&IS=1"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));
    QVERIFY(rv.message == QString("Some Example Message"));
    QVERIFY(rv.fUseInstantSend == 1);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?amount=100&label=Some Example&message=Some Example Message&IS=Something Invalid"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));
    QVERIFY(rv.message == QString("Some Example Message"));
    QVERIFY(rv.fUseInstantSend != 1);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?IS=1"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.fUseInstantSend == 1);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF?IS=0"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.fUseInstantSend != 1);

    uri.setUrl(QString("amero:AbnaQaoAe2XcLtK4iJZe9gHs1PUgJX2HaF"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.fUseInstantSend != 1);
}
