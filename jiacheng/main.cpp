#include <bits/stdc++.h>

using namespace std;

int n,m;
int f[105][105];
int a[105];
int sum[105];

int main()
{
    cin >> n >> m;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        f[i][0] = sum[i];
    }


    for (int i = 2;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            for (int k = 2;k <= i;k++)
            {
                int temp = sum[i] - sum[k-1];
                f[i][j] = max(f[k-1][j-1] * temp,f[i][j]);
            }
        }

    }
    cout << f[n][m];
    return 0;
}
