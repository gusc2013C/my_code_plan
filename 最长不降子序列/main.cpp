#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[5005],f[5005];
int ans;

int main()
{
    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= i-1;j++)
        {
            if (a[i] > a[j])
            {
                f[i] = max(f[i],f[j]+1);
                ans = max(f[i],ans);
            }
        }
    }

    cout << ans+1;

    return 0;
}
