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
    if (a.length() == b.length())
    {
        for(int i = 0 ; i<a.length() ; i++)
        {
            //1  2  3 больше чем 1  2
            if (i == b.length()-2)
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
    return 0;
}
QList<int> getUniqueNums(QList<int> &a)
{
    QList<int> copy = a;
    QList<int> CounterList;
    int j=0;
    CounterList.append(a.at(0));
    //собираю список уникальных значений
    for (int i =0;i<copy.length();i++)
    {
        if(copy.contains(CounterList.at(j)))
        {
            continue;
        }
        else
        {
            CounterList.append(copy.at(i));
            j++;
        }
    }
    return CounterList;
}

int HowItsGrow(QList<int> &a)
{
    int IdealCounter = 0;
    int MaxCount = 0;
    QList<int> copy = a;
    QList<int> CounterList= getUniqueNums(copy);
    foreach(int tet,CounterList)
    {
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
                    MaxCount = IdealCounter;
                    IdealCounter = tet;
                }
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

MyHash2 CountsIn(const QList<QList<int> > &list)
{
    MyHash2 result;
    QList<int> subresult;
    //помнит набор цифр наличие которых надо проверять
    QList<int> cont;
    //выбрал от чего отталкиваться
    foreach(QList<int> f,list)
    {
        if (f.count()>0)
        {
            cont = f;
        }
    }
    //дополняю исходное цифрами которые есть в других строках
    foreach(QList<int> list0, list)
    {
        foreach (const int f,list0)
        {
            if (cont.contains(f)==false)
            {
                cont.append(f);
            }
        }
    }
    //сортирую сборку
    SimpleBubbleSotring(cont);
    //собираю результат
    int j=0;
    for (int i = 0;i<cont.length();i++)
    {
        j=0;
        foreach(QList<int> list0, list)
        {
            j++;
            if (list0.contains(cont.at(i))==true)
            {
                subresult.append(j);
            }

        }
        result.insert(cont.at(i),subresult);
        subresult.clear();
    }
    //возвращаю его
    return result;
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

bool IsItReversionF(const QList<int> &a, const QList<int> &b)
{
    if (SimpleBubbleSotring(a)== SimpleBubbleSotring(b))
    {
        return true;
    }
    else
    {
        return false;
    }
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

MyHash2 CollectionUtilities::TableOfIncl(const QList<QList<int> > &input)
{
    return CountsIn(input);
}

bool CollectionUtilities::ComparePermutation_real(const QList<QList<int> > &a_and_b)
{
    return IsItReversionF(a_and_b.at(0),a_and_b.at(1));
}

int CollectionUtilities::CompareQlists_real(const QList<QList<int> > &a_and_b)
{
    QList<int> fassad1 = a_and_b.at(0);
    QList<int> fassad2 = a_and_b.at(1);
    int result = aIsThisBigger(fassad1,fassad2);
    return result;
}
//задача 8
QList<int> CollectionUtilities::SortingListOfLists (const QList<QList<int> > &input)
{
    return SimpleBubbleSotring(UnitedWeStrong(input));
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
    return HowItsGrow(copy);
}




