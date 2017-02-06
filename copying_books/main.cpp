#include <bits/stdc++.h>

using namespace std;

const int INF = 10000005;

int t;

int main()
{
    cin >> t;

    for(int x = 1;x <= t;x++)
    {
        int f[505][505];
        int q[505];
        int sum[505];
        int m,n;

        cin >> m >> n;

        for (int i = 1;i <= m;i++)
        {
            cin >> q[i];
            sum[i] = sum[i-1] + q[i];

            f[i][1] = sum[i];
        }

        for (int i = 2;i<= m;i++)
        {
            for (int j = 2;j <= n;j++)
            {
                f[i][j] = INF;

                for (int x = j;)
            }
        }
    }

    return 0;
}
