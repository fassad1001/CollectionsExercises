#include "CollectionUtilities.h"

CollectionUtilities::CollectionUtilities()
{
}

QList<int> CollectionUtilities::reverse(const QList<int> &list)
{
    QList<int> reversed;

    foreach(const int e, list)
    {
        reversed.prepend(e);
    }

    return reversed;
}

QList<int> CollectionUtilities::sort(const QList<int> &list)
{
    QList<int> reversed = list;
    if (list.length() > 0)
    {
        int key = 0;
        int min = reversed.first();
        for (int i=0; i<reversed.length();i++)
        {
            min = reversed.at(i);
            for (int j=i; j<reversed.length();j++)
            {
                if(reversed.at(j)<=min)
                {
                    min = reversed.at(j);
                    key = j;
                }
            }
            reversed.swap(i, key);
        }
        return reversed;
    }
    else
    {
        return list;
    }
}
