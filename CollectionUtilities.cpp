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
    QList<int> sorting = list;
    qSort(sorting.begin(), sorting.end());
    return sorting;
}

QList<int> CollectionUtilities::concatList(const QList<QList<int> > &lists)
{
    QList<int> result;
    foreach(const QList<int> sublist, lists)
    {
        result<<sublist;
    }
    return result;

}


MyHash CollectionUtilities::CountNums(const QList<int> &list)
{
    int myNumCount = 0;
    MyHash result;
    int myNum = 0;
    if (list.count()>=1)
    {
        myNum = list.at(0);
        for(int i = 0;i<list.count();i++)
        {
            if (myNum == list.at(i))
            {
                myNumCount ++;
                if(i == (list.count()-1))
                {
                    result.insert(myNum,myNumCount);
                }
            }
            else
            {
                result.insert(myNum,myNumCount);
                myNum = list.at(i);
                myNumCount = 1;
                result.insert(myNum,myNumCount);
                if(i == (list.count()-1))
                {
                    return result;
                }
            }
            if (i==(list.count()-1))
            {
                return result;
            }
        }
    }
}

MyHash2 CollectionUtilities::TableOfIncl(const QList<QList<int> > &input)
{
    return CountsIn(input);
}

bool CollectionUtilities::ComparePermutation_real(const QList<int> &a, const QList<int> &b)
{
    if(a.length()!=b.length())
    {
        return false;
    }
    if (a.isEmpty() || b.isEmpty())
    {
        return false;
    }
    QList<int> sortA = a;
    QList<int> sortB = b;
    qSort(sortA.begin(),sortA.end());
    qSort(sortB.begin(),sortB.end());
    if (sortA == sortB)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int CollectionUtilities::CompareQlists_real(const QList<int> &a, const QList<int> &b)
{
    QList<int> fassad1 = a;
    QList<int> fassad2 = b;
    int result = compare(fassad1,fassad2);
    return result;
}
//задача 8
QList<QList<int> > CollectionUtilities::SortingListOfLists (const QList<QList<int> > &input)
{
    QList<QList<int> > reversed = input;
    if (input.length() > 0)
    {
        int key = 0;
        QList<int> min = reversed.first();
        for (int i=0; i<reversed.length();i++)
        {
            min = reversed.at(i);
            for (int j=i+1; j<reversed.length();j++)
            {
                if((compare(reversed.at(j),min))==(-1))
                {
                    min = reversed.at(j);
                    key = j;
                    reversed.swap(i, key);
                }
            }
        }
        return reversed;
    }
    else
    {
        return reversed;
    }
}
//задача 9
MyHash2 CollectionUtilities::TableOfIncludes_real(const QList<QList<int> > &input)
{
    return CountsIn(input);
}
//задача 10
int CollectionUtilities::MaxUpNumbers_real(const QList<int> &input)
{
    QList<int> copy = input;
    return HowItsGrowv2(copy);
}




