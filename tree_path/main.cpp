#include<iostream>

using namespace std;

const int maxn = 100005;

int w[maxn << 1],int e[maxn << 1],int next[maxn << 1],head[maxn << 1];

int dist[maxn];

void search(int a,int len,int fa)
{
    dist[a] = len;

    for (int p = head[a];p != 0;p = next[p])
    {
        if (edge[p] != fa) search(edge[p],len+w[p],a);
    }

    return;
}
