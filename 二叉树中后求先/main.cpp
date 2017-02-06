#include<iostream>
#include<cstring>

using namespace std;

char m[9],a[9];

void search(int ml,int mr,int al,int ar)
{
    if ((ml > mr) || (al > ar)) return;

    cout << a[ar];

    for (int i = ml;i <= mr;i++)
    {
        if (m[i] == a[ar])
        {
            search(ml,i-1,al,al+i-ml-1);
            search(i+1,mr,al+i-ml,ar-1);
        }
    }
}


int main()
{
    cin >> m;
    cin >> a;

    int mm = 0,aa = 0;

    for (int i = 0;i < 8;i++)
    {
        if (m[i] != 0) mm++;
        if (a[i] != 0) aa++;
    }

    search(0,mm-1,0,aa-1);

    return 0;
}
