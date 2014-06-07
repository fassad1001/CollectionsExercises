#ifndef TCOLLECTIONUTILITIES_H

#define TCOLLECTIONUTILITIES_H

#include <QtTest/QtTest>

#include "CollectionUtilities.h"

class TCollectionUtilities : public QObject
{
    Q_OBJECT
public:
    TCollectionUtilities();

private slots:
    void TestListReverse_data();
    void TestListReverse();
    //задача 1
    void TestSort_data();
    void TestSort();
    //задача 2
    void TestForCont_data();
    void TestForCont();
    //задача 3
    //задача 4
    void TestCountNumbers_data();
    void TestCountNumbers();
    //задача 5
    void TestComparePermutation_data();
    void TestComparePermutation();
    //задача 7
    void TestCompareQlists_data();
    void TestCompareQlists();
    //задача 8
    void TestSortOfQLists_data();
    void TestSortOfQLists();
    //задача 9
    void TestTableOfIncludes_data();
    void TestTableOfIncludes();
    //задача 10
    void TestMaxUpNumbers_data();
    void TestMaxUpNumbers();
};

#endif // TCOLLECTIONUTILITIES_H
