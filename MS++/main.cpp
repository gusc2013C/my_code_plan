#include <bits/stdc++.h>

#define INF 100000000

using namespace std;

int n,m;
int pre[1000005],a[1000005],dp[1000005];

int main()
{
    int maxx = 0;

    while (cin >> m >> n)
    {
        memset(pre,0,sizeof(pre));
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));

        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }


        for (int i = 1;i <= m;i++)
        {
            maxx = -INF;
            for (int j = i;j <= n;j++)
            {
                dp[j] = max(dp[j-1],pre[j-1]) + a[j];

                pre[j-1] = maxx;

                maxx = max(maxx,dp[j]);
            }
        }

        cout << maxx << endl;
    }
    return 0;
}

