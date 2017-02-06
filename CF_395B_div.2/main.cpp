#include <bits/stdc++.h>

using namespace std;

int a[200005];
int ans[200005];
int n;

int main()
{
    scanf("%d",&n);

    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        ans[i] = -1000000005;
    }

    for (int i = 1;i <= n - i + 1;i += 2)
    {
        ans[n-i+1] = a[i];
        ans[i] = a[n-i+1];
    }

    for (int i = 1;i <= n;i++)
    {
        if (ans[i] == -1000000005) ans[i] = a[i];
    }

    for (int i = 1;i <= n;i++)
    {
        printf("%d ",ans[i]);
    }

    return 0;
}
