#include <iostream>
#include <algorithm>

using namespace std;

int t,m;
int v[1005],cost[1005],f[1005];

int main()
{
    cin >> t >> m;

    for (int i = 1;i <= m;i++)\
    {
        cin >> cost[i] >> v[i];
    }

    for (int i = 1;i <= m;i++)
    {
        for (int j = t;j >= cost[i];j--)
        {
            f[j] = max(f[j - cost[i]] + v[i],f[j]);
        }
    }

    cout << f[t];

    return 0;
}
