#ifndef COLLECTIONUTILITIES_H

#define COLLECTIONUTILITIES_H

#include <QtCore>

class MyHash : public QHash< int, int >
{
public:
   MyHash& insertInc(const int key, const int value)
   {
       insert(key, value);
       return *this;
   }
};
Q_DECLARE_METATYPE(MyHash)

class CollectionUtilities
{
public:
    CollectionUtilities();

    static QList<int> reverse(const QList<int> &list);
    static QList<int> sort(const QList<int> &list);
    static QList<int> concatList(const QList< QList<int> > &lists);
    static QList<int> AdvancedSorting(const QList< QList<int> > &lists);
    static MyHash CountNums(const QList<int> &list);
};

#endif // COLLECTIONUTILITIES_H
