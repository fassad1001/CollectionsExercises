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
};

#endif // TCOLLECTIONUTILITIES_H
