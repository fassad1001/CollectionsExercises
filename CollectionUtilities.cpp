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

//Функции для повторного использования (down)
QList<int> SimpleBubbleSotring (const QList<int> &list)
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
QList<int> UnitedWeStrong (const QList<QList<int> > &lists)
{
    QList<int> result;
    foreach(const QList<int> sublist, lists)
    {
        foreach(const int e, sublist)
        {
            result.append(e);
        }
    }
    return result;
}
int aIsThisBigger(QList<int> &a, QList<int> &b)
{
    //если последовательность а больше по размеру б то а больше б
    //если последовательность а

    if (a.length() == b.length())
    {
        for(int i = 0 ; i<a.length() ; i++)
        {
            //1  2  3 больше чем 1  2
            if (i == b.length()-1)
            {
                if (a.at(i) == b.at(i))
                {
                    return 1;
                }
            }
            //5  5  5 больше чем 5  4  5
            if (a.at(i)> b.at(i))
            {
                return 1;
            }

        }
        //5  5  5 равно 5  5  5
        if (a == b)
        {
            return 0;
        }
        return -1;
    }
    return -1;
}
int HowItsGrow(QList<int> &a)
{
    int IdealCounter = 0;
    int MaxCount = 0;
    foreach(const int d, a)
    {
        if (d == IdealCounter)
        {
            IdealCounter ++;
        }
        else
        {
            if (IdealCounter>MaxCount)
            {
                MaxCount = IdealCounter+1;
                IdealCounter = 0;
            }
        }
    }
    return MaxCount;
}
MyHash CountNumbersFast(const QList<int> &list)
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
                qWarning()<<"num = "<<myNum<<";"<<"myNumCount = "<<myNumCount;
                if(i == (list.count()-1))
                {
                    qWarning()<<"insert:("<<myNum<<":"<<myNumCount<<")";
                    result.insert(myNum,myNumCount);
                }
            }
            else
            {
                result.insert(myNum,myNumCount);
                myNum = list.at(i);
                myNumCount = 1;
                qWarning()<<"insert:("<<myNum<<":"<<myNumCount<<")";
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
MyHash CountsIn(const QList<QList<int> > &list)
{
    int myNumCount = 0;
    MyHash result;
    int myNum = 0;

    foreach(QList<int> list0, list)
    {
        foreach (const int f,list0)
        {
        }
    }

//    if (list.count()>=1)
//    {
//        myNum = list.at(0);
//        for(int i = 0;i<list.count();i++)
//        {
//            if (myNum == list.at(i))
//            {
//                myNumCount ++;
//                qWarning()<<"num = "<<myNum<<";"<<"myNumCount = "<<myNumCount;
//                if(i == (list.count()-1))
//                {
//                    qWarning()<<"insert:("<<myNum<<":"<<myNumCount<<")";
//                    result.insert(myNum,myNumCount);
//                }
//            }
//            else
//            {
//                result.insert(myNum,myNumCount);
//                myNum = list.at(i);
//                myNumCount = 1;
//                qWarning()<<"insert:("<<myNum<<":"<<myNumCount<<")";
//                result.insert(myNum,myNumCount);
//                if(i == (list.count()-1))
//                {
//                    return result;
//                }
//            }
//            if (i==(list.count()-1))
//            {
//                return result;
//            }
//        }
//    }
}
int FindMin(const QList<int> &r)
{
    if (r.count()>0)
    {
        int min = r.at(0);
        foreach(const int f,r)
        {
            if(f<min)
            {
                min = f;
            }
        }
        return min;
    }
    return -999;
}
int FindMin2_0(const QList<QList<int> > &r)
{
    int min = FindMin(r.at(0));
    foreach (QList<int> f, r)
    {
        if (FindMin(f)<min)
        {
            min = FindMin(f);
        }
    }
    return min;
}

//Функции для повторного использования (up)

QList<int> CollectionUtilities::concatList(const QList<QList<int> > &lists)
{
    QList<int> result;
    foreach(const QList<int> sublist, lists)
    {
        foreach(const int e, sublist)
        {
            result.append(e);
        }
    }
    return result;

}

QList<int> CollectionUtilities::AdvancedSorting(const QList<QList<int> > &lists)
{
    return SimpleBubbleSotring(UnitedWeStrong(lists));
}

MyHash CollectionUtilities::CountNums(const QList<int> &list)
{
    return CountNumbersFast(list);
}

