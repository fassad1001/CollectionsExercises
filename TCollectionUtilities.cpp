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

void TCollectionUtilities::TestSort_data()
{
    QTest::addColumn< QList<int> >("list");
    QTest::addColumn< QList<int> >("sorted");

    QTest::newRow("empty-list") << QList<int>()
                                << QList<int>();

    QTest::newRow("single-element-list") << (QList<int>() << 1)
                                         << (QList<int>() << 1);

    QTest::newRow("two-elements-list1") << (QList<int>() << 1 << 2)
                                        << (QList<int>() << 1 << 2);

    QTest::newRow("two-elements-list2") << (QList<int>() << 2 << 1)
                                        << (QList<int>() << 1 << 2);

    QTest::newRow("three-elements-list1") << (QList<int>() << 1 << 2 << 3)
                                          << (QList<int>() << 1 << 2 << 3);

    QTest::newRow("three-elements-list3") << (QList<int>() << 1 << 3 << 2)
                                          << (QList<int>() << 1 << 2 << 3);

    QTest::newRow("three-elements-list4") << (QList<int>() << 3 << 2 << 1)
                                          << (QList<int>() << 1 << 2 << 3);

    QTest::newRow("three-elements-list5") << (QList<int>() << 2 << 1 << 3)
                                          << (QList<int>() << 1 << 2 << 3);

    QTest::newRow("ten-elements-list") << (QList<int>() << 2 << 1 << 3 << 3 << 4 << 2 << 5 << 6 << 7 << 6)
                                       << (QList<int>() << 1 << 2 << 2 << 3 << 3 << 4 << 5 << 6 << 6 << 7);
}

void TCollectionUtilities::TestSort()
{
    QFETCH(QList<int>, list);
    QFETCH(QList<int>, sorted);

    QCOMPARE(CollectionUtilities::sort(list), sorted);
}
