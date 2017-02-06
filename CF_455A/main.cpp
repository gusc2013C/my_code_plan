#include <bits/stdc++.h>

using namespace std;

long long f[500005];
long long a[500005];
long long num[500005];

int main()
{
    long long n;

    while (cin >> n)
    {
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        num[a[i]]++;
    }

    f[1] = num[1];

    for (int i = 2;i <= 500000;i++)
    {
        f[i] = max(f[i-1],f[i-2] + (long long )i * num[i]);
    }

    cout << f[500000] << endl;
    }

    return 0;
}
