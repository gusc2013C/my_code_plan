#include <bits/stdc++.h>

using namespace std;

bool flag[1005];
int g[1005][1005];
int avail[1005];

int maxtree()
{
    int ans = 0;

    flag[1] = true;

    for (int i = 1;i <= n;i++)
    {
        avail[i] = g[1][i];
    }

    for (int i = 1;i <= n-1;i++)
    {
        int min_v = __INT32_MAX__;
        int min_p = 0;

        for (int j = 1;j <= n;j++)
        {
            if (flag[j] == false&&avail[j] < min_v)
            {
                min_v = avail[j];
                min_p = j;
            }
        }

        flag[min_p] = true;

        ans += min_v;

        for (int j = 1;j <= n;j++)
        {
            if (flag[j] == false && g[j,min_p] < avail[j]) avail[j] = g[j,min_p];
        }
    }

    return ans;

}

int main()
{
    return 0;
}
