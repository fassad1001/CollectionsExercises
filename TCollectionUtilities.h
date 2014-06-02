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

    void TestSort_data();
    void TestSort();

    void TestForCont_data();
    void TestForCont();

    void AdvancedSorting_data();
    void AdvancedSorting();

    void CountNumbers_data();
    void CountNumbers();
};

#endif // TCOLLECTIONUTILITIES_H
