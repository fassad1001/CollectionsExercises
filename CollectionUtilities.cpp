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
