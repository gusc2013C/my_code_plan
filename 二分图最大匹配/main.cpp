#include <bits/stdc++.h>

using namespace std;

int ma[1005][1005];
int n,m,e;
bool f[1005];
int match[1005];
int ans;

int dfs(int a);

int main()
{
    cin >> n >> m >> e;

    for (int i = 1;i <= e;i++)
    {
        int t1,t2;
        cin >> t1 >> t2;

        if (t2 > m) continue;

        ma[t1][t2] = 1;
        ma[t2][t1] = 1;
    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            f[j] = false;
        }

        if (dfs(i)) ans++;
    }

    cout << ans;

    return 0;
}

int dfs(int a)
{
    for (int i = 1;i <= m;i++)
    {
        if ((!f[i]) && ma[a][i])
        {
            f[i] = true;

            if (!match[i] || dfs(match[i]))
            {
                match[a] = i;

                return 1;
            }
        }
    }

    return 0;
}
