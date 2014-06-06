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

//Функции для повторного использования (down)
QList<int> concate (const QList<QList<int> > &lists)
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
int compare(const QList<int> &a,const QList<int> &b)
{
    if (a==b)
    {
        return 0;
    }
    //1 2 3 больше ...
    if (b.isEmpty())
    {
        return 1;
    }
    //... меньше 1 2 3
    if (a.isEmpty())
    {
        return -1;
    }
    //5  5  5 равно 5  5  5
    //... равно ...
    for(int i = 0 ; i<a.length() ; i++)
    {
        if (a.at(i)==b.at(i))
        {
            //1 2 3 4 5 6 7 8 больше чем 1 2 3 4 5
            if (i+1==b.length() && i+1<a.length())
            {
                return 1;
            }
            //1 2 3 4 5 меньше чем 1 2 3 4 5 6 7 8
            if (i == a.length()-1 && i+1<b.length())
            {
                return -1;
            }
        }
        //5  5  5 больше чем 5  4  5
        if (a.at(i)> b.at(i))
        {
            return 1;
        }

        if(a.at(i)<b.at(i))
        {
            return -1;
        }
    }
}
QList<int> getUniqueNums(QList<int> &a)
{
    QList<int> copy = a;
    QList<int> CounterList;
    int j=0;
    CounterList.append(a.at(0));
    //собираю список уникальных значений
    for (int i =1;i<copy.length();i++)
    {
        if(CounterList.contains(copy.at(i)))
        {
            continue;
        }
        else
        {
            CounterList.append(copy.at(i));
            j++;
        }
    }
    qWarning()<<"fdsa"<<"="<<CounterList.length();
    return CounterList;
}

int HowItsGrow(QList<int> &a)
{
    int IdealCounter = 0;
    int MaxCount = 0;
    QList<int> copy = a;
    QList<int> CounterList= getUniqueNums(copy);
    int iterator=0;
    foreach(int tet,CounterList)
    {
        iterator=0;
        IdealCounter = tet;
        int Ticks = 0;
        foreach(const int d, a)
        {
            iterator++;
            if (d == IdealCounter)
            {
                IdealCounter ++;
                Ticks++;
                if(iterator==a.length())
                {
                    if (Ticks>MaxCount)
                    {
                        MaxCount = Ticks;
                        IdealCounter = tet;
                        break;
                    }
                }
            }
            else
            {
                if (Ticks>MaxCount)
                {
                    MaxCount = Ticks;
                    IdealCounter = tet;
                    break;
                }
            }
        }
    }
    return MaxCount;
}
int HowItsGrowv2(QList<int> &a)
{
    QList<int> copy = a;
    if (copy.length()==1)
    {
        return 1;
    }
    int count = 1;
    int maxUp = 1;
    if (copy.length()>1)
    {
        for (int i =1 ; i <copy.length();i++)
        {
            if (a.at(i)>a.at(i-1))
            {
                count ++;
                if (count>maxUp)
                {
                    maxUp=count;
                }
            }
            else
            {
                if(count>maxUp)
                {
                    maxUp=count;
                }
                count =1;
            }
        }
        return maxUp;
    }
    else
    {
        return 0;
    }
    if (a.isEmpty())
    {
        return 0;
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

//Функции для повторного использования (up)

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




