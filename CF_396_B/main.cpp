#include <bits/stdc++.h>

using namespace std;

int a[100005];
int cha[100005];
int n;

int main()
{
    scanf("%d",&n);

    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);

    for (int i = 1;i <= n-2;i++)
    {
        if (a[i+1] - a[i] < a[i+2] && a[i+1] + a[i] > a[i+2])
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO";

    return 0;
}
