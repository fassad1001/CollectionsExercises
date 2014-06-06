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

class MyHash2 : public QHash< int, QList<int> >
{
public:
   MyHash2& insertInc(const int key, const QList<int> value)
   {
       insert(key, value);
       return *this;
   }
};
Q_DECLARE_METATYPE(MyHash2)


class CollectionUtilities
{
public:
    CollectionUtilities();

    static QList<int> reverse(const QList<int> &list);
    static QList<int> sort(const QList<int> &list);
    static QList<int> concatList(const QList< QList<int> > &lists);
    static MyHash CountNums(const QList<int> &list);
    static MyHash2 TableOfIncl(const QList<QList<int> > &input);
    //задача 5
    static bool ComparePermutation_real (const QList<int> &a, const QList<int> &b);
    //задача 7
    static int CompareQlists_real (const QList<int> &a, const QList<int> &b);
    //задача 8   
    static QList<QList<int> > SortingListOfLists (const QList<QList<int> > &input);
    //задача 9
    static MyHash2 TableOfIncludes_real (const QList<QList<int> > &input);
    //задача 10
    static int MaxUpNumbers_real (const QList<int> &input);
};

#endif // COLLECTIONUTILITIES_H
