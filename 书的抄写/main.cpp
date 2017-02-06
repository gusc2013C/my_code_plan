#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[505];

bool check(int a);

int main()
{
    cin >> n >> m; // n本书 m个人

    int l = 1;
    int r = 0;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        r += a[i];
    }

    while (l < r)
    {
        int mid = (l + r) >> 1;

        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    int head = 1;
    int temp = 0;

    for (int i = 1;i <= n;i++)
    {
        if (temp + a[i] <= l)
        {
            temp += a[i];
        }
        else
        {
            cout << head << " " << i - 1 << endl;
            temp = a[i];
            head = i;
        }
    }

    cout << head << " " << n << endl;

    return 0;
}

bool check(int b)
{
    int temp = 0;
    int num = 1;

    for (int x = 1;x <= n;x++)
    {
        if (temp + a[x] <= b)
        {
            temp += a[x];
        }
        else if (a[x] > b) return false;
        else
        {
            temp = a[x];
            num++;
        }
    }

    if (num > m) return false;
    else return true;
}
