#include <bits/stdc++.h>

using namespace std;

int n,m;
int a,b;
long long f[25][25];
bool g[25][25];

int main()
{
    cin >> n >> m;
    cin >> a >> b;

    g[a][b] = true;
    g[a+1][b-2] = true;
    g[a+2][b-1] = true;
    g[a+2][b+1] = true;
    g[a+1][b+2] = true;
    g[a-1][b+2] = true;
    g[a-2][b+1] = true;
    g[a-2][b-1] = true;
    g[a-1][b-2] = true;

    f[0][0] = 1;

    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= m;j++)
        {
            if (g[i][j]) f[i][j] = 0;
            else if ((i == j) && (i == 0))
            {
                continue;
            }
            else if (i == 0) f[i][j] = f[i][j-1];
            else if (j == 0) f[i][j] = f[i-1][j];
            else
            {
                f[i][j] = f[i][j-1] + f[i-1][j];
            }
        }
    }

    cout << f[n][m];

    return 0;
}
