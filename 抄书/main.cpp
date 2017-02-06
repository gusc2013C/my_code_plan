#include <iostream>

using namespace std;

int book[1000];
int m,k;

int main()
{
    cin >> m >> k;

    for (int i = 1;i <= m;i++)
    {
        cin >> book[i];
    }

    int l,r,mid;

    l = 1; r = m;

    while (l < r)
    {
        mid = (l + r) >> 1;

        int t1,t2;

        for (int i = 1;i <= m;i++)
        {

            t1 = 0; t2 = 1;

            if (t1+book[i]>mid)
            {
                t1 = 0;
                t2 ++;
            }
            else
            {
                t1 += book[i];
            }
        }

        if (t2 > k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }

    cout << l;

    return 0;
}
