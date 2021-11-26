#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

int array_remove_less(int* N, int length, int k) {
    int v, p, j = 0;
    for (int i = 0; i < length; )
    {
        p = i + 1;
        v = N[i];
        while ((p < length) && (N[p] == v))
        {
            p++;
        }
        if ((p - i) < k)
        {
            i = p;
        }
        else
        {
            while (i < p)
            {
                N[j++] = N[i++];
            }
        }
    }
    return j;
}

int array_remove_equals(int* N, int length, int k) {
    int v, p, j = 0;
    for (int i = 0; i < length; )
    {
        p = i + 1;
        v = N[i];
        while ((p < length) && (N[p] == v))
        {
            ++p;
        }
        if ((p - i) == k)
        {
            i = p;
        }
        else
        {
            while (i < p)
            {
                N[j++] = N[i++];
            }
        }
    }
    return j;
}

int array_remove_more(int* N, int length, int k) {
    int v, p, j = 0;
    for (int i = 0; i < length; )
    {
        p = i + 1;
        v = N[i];
        while ((p < length) && (N[p] == v))
        {
            ++p;
        }
        if ((p - i) > k)
        {
            i = p;
        }
        else
        {
            while (i < p)
            {
                N[j++] = N[i++];
            }
        }
    }
    return j;
}

void Print()
{
    srand(time(0));
    int k = 0;
    int usl = 1;
    cout << " ВВеди какую часть массива нужно удалиь (1 - Больше k 2 - Равно k 3 - Меньше k)" << endl;
    cin >> usl;
    cout << "ВВедите к " << endl;;
    cin >> k;
    int N[20];
    for (int i = 0; i < 20; i++)
    {
        N[i] = rand() % 10;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << N[i] << " ";
    }
    cout << endl;
    int length = 20;

    switch (usl)
    {
    case 1:

        length = array_remove_more(N, length, k);
        for (int i = 0; i < length; ++i)
        {
            cout << N[i] << ' ';
        }
        break;
    case 2:


        length = array_remove_equals(N, length, k);
        for (int i = 0; i < length; ++i)
        {
            cout << N[i] << ' ';
        }
        break;
    case 3:

        length = array_remove_less(N, length, k);
        for (int i = 0; i < length; ++i)
        {
            cout << N[i] << ' ';
        }
        break;
    }
}

int main()
{
    setlocale(0, "");
    char uslovie = 0;
    cout << "Начать вычисления - 1 Выйти - 0" << endl;
    cin >> uslovie;
    cout << endl;
    while (uslovie != '0')
    {
        Print();
        cout << endl;
        cout << "повтоорить вычисление 1 - да 0 - нет" << endl;
        cin >> uslovie;
        cout << endl;
    }

    return 0;
}