#include "TCollectionUtilities.h"
#include <QHash>
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
//задача 1
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
//задача 1
void TCollectionUtilities::TestSort()
{
    QFETCH(QList<int>, list);
    QFETCH(QList<int>, sorted);

    QCOMPARE(CollectionUtilities::sort(list), sorted);
}
//задача 2
void TCollectionUtilities::TestForCont_data()
{
    QTest::addColumn < QList< QList<int> > > ("listOfLists");
    QTest::addColumn < QList<int> > ("expected");

    QTest::newRow("nameoftest1") << (QList<QList<int> >() << (QList<int>()<<1) << (QList<int>()<<2) << (QList<int>()<<3))
                                 << (QList<int>()<<1<<2<<3);
    QTest::newRow("nameoftest2") << (QList<QList<int> >() << (QList<int>()<<1<<2<<3) << (QList<int>()<<4) << (QList<int>()<<5))
                                 << (QList<int>()<<1<<2<<3<<4<<5);
    QTest::newRow("nameoftest3") << (QList<QList<int> >() << (QList<int>()<<1<<2) << (QList<int>()<<3<<4) << (QList<int>()<<5<<6))
                                 << (QList<int>()<<1<<2<<3<<4<<5<<6);
    QTest::newRow("nameoftest4") << (QList<QList<int> >() << (QList<int>()) << (QList<int>()) << (QList<int>()))
                                 << (QList<int>());
}
//задача 2
void TCollectionUtilities::TestForCont()
{
    QFETCH(QList<QList<int> >, listOfLists);
    QFETCH(QList<int>, expected);

    QCOMPARE(CollectionUtilities::concatList(listOfLists), expected);

}
//задача 3



//задача 4
void TCollectionUtilities::CountNumbers_data()
{
    QTest::addColumn < QList<int> > ("list");
    QTest::addColumn < MyHash > ("expected");

    QTest::newRow("blank") << (QList<int>())
                                      << (MyHash());

    QTest::newRow("single-list") << (QList<int>() << 1)
                                 << (MyHash()
                                     .insertInc(1, 1));

    QTest::newRow("two-elems-list1") << (QList<int>() << 1 << 1)
                                     << (MyHash()
                                         .insertInc(1, 2));

    QTest::newRow("two-elems-list12") << (QList<int>() << 1 << 2)
                                      << (MyHash()
                                          .insertInc(1, 1)
                                          .insertInc(2, 1));

    QTest::newRow("many-elems-list12") << (QList<int>() << 1 << 2 << 3<<3<<5<<5<<5)
                                      << (MyHash()
                                          .insertInc(1, 1)
                                          .insertInc(2, 1)
                                          .insertInc(3,2)
                                          .insertInc(5,3));

}
//задача 4
void TCollectionUtilities::CountNumbers()
{

    QFETCH(QList<int>, list);
    QFETCH(MyHash, expected);

    QCOMPARE(CollectionUtilities::CountNums(list), expected);
}
//задача 5
void TCollectionUtilities::ComparePermutation_data()
{
    QTest::addColumn <QList<int> > ("input1");
    QTest::addColumn <QList<int> > ("input2");
    QTest::addColumn <bool > ("output");

    QTest::newRow("ComparePermutation_test_1 blank blank") <<(QList<int>())
                                                           <<(QList<int>())
                                                           <<(false);

    QTest::newRow("ComparePermutation_test_2 blank notblank") <<(QList<int>())
                                                           <<(QList<int>()<<1<<10<<2)
                                                           <<(false);

    QTest::newRow("ComparePermutation_test_2 notblank notblank") <<(QList<int>()<<1)
                                                           <<(QList<int>()<<1)
                                                           <<(true);

    QTest::newRow("ComparePermutation_test_3 notblank notblank") <<(QList<int>()<<1<<2<<10)
                                                           <<(QList<int>()<<1<<10<<2)
                                                           <<(true);

    QTest::newRow("ComparePermutation_test_3 notblank notblank") <<(QList<int>()<<1<<2<<10)
                                                           <<(QList<int>()<<1<<10<<2<<15)
                                                           <<(false);

}
//задача 5
void TCollectionUtilities::ComparePermutation()
{
    QFETCH(QList<int>, input1);
    QFETCH(QList<int>, input2);
    QFETCH(bool, output);

    QCOMPARE(CollectionUtilities::ComparePermutation_real(input1,input2),output);
}
//задача 7
void TCollectionUtilities::CompareQlists_data()
{\
    QTest::addColumn <QList<int> > ("input1");
    QTest::addColumn <QList<int> > ("input2");
    QTest::addColumn <int > ("output");

    QTest::newRow("CompareQlists1 blank blank ") << (QList<int>())
                                                 << (QList<int>())
                                                 <<(0);

    QTest::newRow("CompareQlists2 blank notblank ") << (QList<int>())
                                                 << (QList<int>()<<1<<2<<3)
                                                 <<(-1);

    QTest::newRow("CompareQlists3 notblank blank ") << (QList<int>()<<1<<2<<3)
                                                 << (QList<int>())
                                                 <<(1);

    QTest::newRow("CompareQlists4 notblank notblank ") << (QList<int>()<<1<<2<<3)
                                                 << (QList<int>()<<1<<2<<3)
                                                 <<(0);

    QTest::newRow("CompareQlists5 notblank notblank") << (QList<int>()<<1<<2<<3)
                                                 << (QList<int>()<<4<<5<<6)
                                                 <<(-1);

    QTest::newRow("CompareQlists6 notblank <l notblank") << (QList<int>()<<1<<2<<3)
                                                 << (QList<int>()<<1<<2<<3<<4)
                                                 <<(-1);

    QTest::newRow("CompareQlists6 notblank >l notblank") << (QList<int>()<<1<<2<<3<<4)
                                                 << (QList<int>()<<1<<2<<3)
                                                 <<(1);


}
//задача 7
void TCollectionUtilities::CompareQlists()
{
    QFETCH(QList<int>, input1);
    QFETCH(QList<int>, input2);
    QFETCH(int ,output);

    QCOMPARE(CollectionUtilities::CompareQlists_real(input1,input2),output);
}
//задача 8
void TCollectionUtilities::SortOfQLists_data()
{
    QTest::addColumn <QList<QList<int> > > ("input");
    QTest::addColumn <QList<QList<int> > > ("output");

    QTest::newRow("one list: blank") << (QList<QList<int> >())
                                         <<(QList<QList<int> >());

    QTest::newRow("2 lists: blank") << (QList<QList<int> >() << (QList<int>()))
                                         <<(QList<QList<int> >() << (QList<int>()));

    QTest::newRow("2 lists: blank") << (QList<QList<int> >() << (QList<int>()) << (QList<int>()))
                                         <<(QList<QList<int> >() << (QList<int>()) << (QList<int>()));

    QTest::newRow("2 lists notblank notblank") << (QList<QList<int> >() << (QList<int>()<<1<<23) << (QList<int>()<<1<<15))
                                         <<(QList<QList<int> >() << (QList<int>()<<1<<15) << (QList<int>()<<1<<23));

    QTest::newRow("3 lists notblank blank notblank") << (QList<QList<int> >() << (QList<int>()<<7<<15<<5) << (QList<int>()) << (QList<int>()<<1<<15))
                                                 <<(QList<QList<int> >() << (QList<int>()) << (QList<int>()<<1<<15) << (QList<int>()<<7<<15<<5));
}
//задача 8
void TCollectionUtilities::SortOfQLists()
{
    QFETCH(QList<QList<int> >, input);
    QFETCH(QList<QList<int> >,output);

    QCOMPARE(CollectionUtilities::SortingListOfLists(input),output);
}
//задача 9
void TCollectionUtilities::TableOfIncludes_data()
{
    QTest::addColumn<QList<QList<int> > >("input");
    QTest::addColumn<MyHash2>("output");

    QTest::newRow("TableOfIncludes_test_3")<<( QList<QList<int> >())
                                          <<(MyHash2());

    QTest::newRow("TableOfIncludes_test_1")<<( (QList<QList<int> >()) << (QList<int>()<<5))
                                          <<(MyHash2()
                                             .insertInc(5,QList<int>()<<1));

    QTest::newRow("TableOfIncludes_test_1")<<( (QList<QList<int> >()) << (QList<int>()<<1<<2<<3) <<  (QList<int>()<<1<<2<<3) << (QList<int>()))
                                          <<(MyHash2()
                                             .insertInc(1,QList<int>()<<1<<2)
                                             .insertInc(2,QList<int>()<<1<<2)
                                             .insertInc(3,QList<int>()<<1<<2));

    QTest::newRow("TableOfIncludes_test_1")<<( (QList<QList<int> >()) << (QList<int>()<<1<<2<<3<<5) <<  (QList<int>()<<1<<2<<3))
                                          <<(MyHash2()
                                             .insertInc(1,QList<int>()<<1<<2)
                                             .insertInc(2,QList<int>()<<1<<2)
                                             .insertInc(3,QList<int>()<<1<<2)
                                             .insertInc(5,QList<int>()<<1));
    QTest::newRow("TableOfIncludes_test_2")<<( (QList<QList<int> >()) << (QList<int>()<<5<<5<<5) <<  (QList<int>()<<5<<4<<5))
                                          <<(MyHash2()
                                             .insertInc(5,QList<int>()<<1<<2)
                                             .insertInc(4,QList<int>()<<2));

}
//задача 9
void TCollectionUtilities::TableOfIncludes()
{
    QFETCH(QList<QList<int> >, input);
    QFETCH(MyHash2 ,output);

    QCOMPARE(CollectionUtilities::TableOfIncludes_real(input),output);
}
//задача 10
void TCollectionUtilities::MaxUpNumbers_data()
{
    QTest::addColumn<QList<int> >("input");
    QTest::addColumn<int>("output");

    QTest::newRow("MaxUpNumbers1")<<(QList<int>()<<0<<1<<2<<3<<4<<5<<6<<8)
                                 <<(8);
    QTest::newRow("MaxUpNumbers2")<<(QList<int>())
                                 <<(0);

    QTest::newRow("+---")<<(QList<int>()<<1<<2<<4<<5<<5<<5<<5)
                                     <<(4);
    QTest::newRow("---+")<<(QList<int>()<<5<<5<<5<<5<<6<<7<<8)
                                     <<(4);
    QTest::newRow("--+--")<<(QList<int>()<<5<<5<<5<<6<<7<<7<<7<<7)
                                     <<(3);

    QTest::newRow("MaxUpNumbers3")<<(QList<int>()<<5)
                                 <<(1);
    QTest::newRow("MaxUpNumbers4")<<(QList<int>()<<5<<6)
                                 <<(2);
    QTest::newRow("MaxUpNumbers5")<<(QList<int>()<<5<<6<<7<<5<<5)
                                 <<(3);
}
//задача 10
void TCollectionUtilities::MaxUpNumbers()
{
    QFETCH(QList<int>, input);
    QFETCH(int ,output);

    QCOMPARE(CollectionUtilities::MaxUpNumbers_real(input),output);
}
