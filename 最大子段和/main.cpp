#include <bits/stdc++.h>

using namespace std;

int a[200005],f[200005],sum[200005];
int m,mpos;

int n;
int ans;

int main()
{
    /** \brief main主程序
     *
     * \param f[]动态转移数组 n 数的个数
     * \return 0
     *
     */


    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    ans = -__INT32_MAX__+10;

    /*m = __INT32_MAX__;

    for (int i = 1; i <= n;i++)
    {
        sum[i] = sum[i-1] + a[i];
        if (m > sum[i])
        {
            m = sum[i];
            mpos = i;
        }
    }*/

    for (int i = 1;i <= n;i++)
    {
        f[i] = max(f[i-1],0) + a[i];
        ans = max(f[i],ans);
    }

    cout << ans;

    return 0;
}
