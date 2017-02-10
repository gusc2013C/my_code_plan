#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int v[100005],e[100005],next[200005];
bool flag[100005];
int num[100005];
int maxnode,maxbalance;

void dfs(int a)
{
    int maxsumtree = 0;
    flag[a] = true;
    num[a] = 1;

    for (int i = v[a];i != 0;i = next[i])
    {
        int temp = e[i];

        if (flag[temp]) continue;

        dfs(temp);

        num[a] += num[temp];

        maxsumtree = max(maxsumtree,num[temp]);
    }

    maxsumtree = max(maxsumtree,n - num[a]);

    if(maxsumtree < maxbalance||(maxsumtree==maxbalance && a<maxnode))
    {
        maxnode=a;
        maxbalance=maxsumtree;
    }
}

int main()
{
    //ios::sync_with_stdio(false);

    int t;


    scanf("%d",&t);

    for (int x = 1;x <= t;x++)
    {
    scanf("%d",&n);

    memset(v,0,sizeof(v));
    memset(next,0,sizeof(next));
    memset(e,0,sizeof(e));
    memset(flag,0,sizeof(flag));

    for (int i = 1;i <= n-1;i++)
    {
        int a,b;

        scanf("%d %d",&a,&b);

        e[i] = b;
        next[i] = v[a];
        v[a] = i;
        e[i+n] = a;
        next[i+n] = v[b];
        v[b] = i+n;
    }

    maxbalance = 0x7fffffff;
    maxnode = 0;

    dfs(1);

    printf("%d %d\n",maxnode,maxbalance);
    }

    return 0;
}
