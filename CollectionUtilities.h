#ifndef COLLECTIONUTILITIES_H

#define COLLECTIONUTILITIES_H

#include <QtCore>

class CollectionUtilities
{
public:
    CollectionUtilities();

    static QList<int> reverse(const QList<int> &list);
    static QList<int> sort(const QList<int> &list);
};

#endif // COLLECTIONUTILITIES_H
