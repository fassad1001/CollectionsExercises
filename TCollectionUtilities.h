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
    void CountNumbers_data();
    void CountNumbers();
    //задача 5
    void ComparePermutation_data();
    void ComparePermutation();
    //задача 7
    void CompareQlists_data();
    void CompareQlists();
    //задача 8
    void SortOfQLists_data();
    void SortOfQLists();
    //задача 9
    void TableOfIncludes_data();
    void TableOfIncludes();
    //задача 10
    void MaxUpNumbers_data();
    void MaxUpNumbers();
};

#endif // TCOLLECTIONUTILITIES_H
