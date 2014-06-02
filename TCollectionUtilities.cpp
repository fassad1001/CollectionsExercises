#include "TCollectionUtilities.h"

TCollectionUtilities::TCollectionUtilities()
{
}

void TCollectionUtilities::TestListReverse_data()
{
    QTest::addColumn< QList<int> >("list");
    QTest::addColumn< QList<int> >("reversed");

    QTest::newRow("empty-list") << QList<int>()
                                << QList<int>();

    QTest::newRow("single-element") << (QList<int>() << 1)
                                    << (QList<int>() << 1);

    QTest::newRow("two-equal-elements") << (QList<int>() << 1 << 1)
                                        << (QList<int>() << 1 << 1);

    QTest::newRow("two-elements") << (QList<int>() << 1 << 2)
                                  << (QList<int>() << 2 << 1);

    QTest::newRow("three-elements") << (QList<int>() << 1 << 2 << 3)
                                    << (QList<int>() << 3 << 2 << 1);

    QTest::newRow("four-elements") << (QList<int>() << 1 << 2 << 3 << 4)
                                   << (QList<int>() << 4 << 3 << 2 << 1);

    QTest::newRow("ten-elements") << (QList<int>() << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10)
                                  << (QList<int>() << 10 << 9 << 8 << 7 << 6 << 5 << 4 << 3 << 2 << 1);
}

void TCollectionUtilities::TestListReverse()
{
    QFETCH(QList<int>, list);
    QFETCH(QList<int>, reversed);

    QCOMPARE(CollectionUtilities::reverse(list), reversed);
}
