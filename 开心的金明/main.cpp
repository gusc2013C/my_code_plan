#include <bits/stdc++.h>

using namespace std;

int n,m;
long long f[30005];
int a[30],v[30];

int main()
{
    cin >> n >> m;

    for (int i = 1;i <= m;i++)
    {
        cin >> a[i] >> v[i];
    }

    for (int i = 1;i <= m;i++)
    {
        for (int j = n;j >= a[i];j--)
        {
            f[j] = max(f[j],f[j-a[i]] + a[i] * v[i]);
        }
    }

    cout << f[n];

    return 0;
}
