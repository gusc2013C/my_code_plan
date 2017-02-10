#include <bits/stdc++.h>

using namespace std;

struct node
{
    vector<int> son;
};

int first[10005];
int mid[10005];
node tree[10005];

void dfs(int xl,int xr,int yl,int yr)
{
    if (xl > xr) return;
    int fa = first[xl];

    for (int i = yl;i <= yr;i++)
    {
        if (mid[i] == fa)
        {
            if (i > yl) dfs(xl+1,xl+i-yl,yl,i-1);
            if (i < yr) dfs(xl+i-yl+1,xr,i+1,yr);
            cout << fa << endl;
        }
    }
}

int main()
{
    int n;

    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        cin >> first[i];
    }

    for (int i = 1;i <= n;i++)
    {
        cin >> mid[i];
    }

    dfs(1,n,1,n);
    return 0;
}
