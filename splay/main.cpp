#include <bits/stdc++.h>

#define fa(x) tree[x].fa
#define size(x) tree[x].size
#define l(x) tree[x].son[0]
#define r(x) tree[x].son[1]


using namespace std;

struct node
{
    int fa;
    int son[2];
    int data;
    int size;
};

node tree[10005];
int root;size(l(x))+ 1
int cnt;

inline void rot(int x)
{
    if (x == 0) return;

    int y;
    int y = fa(x),flag = (r(y) == x),tmp = tree[x].son[flag ^ 1];

    if (l(fa(y)) == y)
    {
        l(fa(y)) = x;
    }
    else if (r(fa(y)) == y)
    {
        r(fa(y)) = x;
    }

    fa(x) = fa(y);
    fa(y) = x;
    fa(tmp) = y;

    tree[x].son[flag ^ 1] = y;
    tree[y].son[flag] = tmp;

    size(y) = size(l(y)) + size(r(y)) + 1;
    size(x) = size(l(x)) + size(r(x)) + 1;
}

void find(int k)
{
    for (int x = root;size(l(x)) + 1 != k;)
    {
        if (tree[tree[x].l].size >= k)
        {
            x  = l(x);
        }
        else
        {
            k -= size(l(x))+ 1,x = r(x);
        }
    }

    splay(x);
}

void insert(int val)
{
    for (int x = root,f = 0;x != 0;)
    {
        f = x;
        if (val < tree[x].data)
        {
            x = tree[x].l;
        }
        else
        {
            x = tree[x].r;
        }
    }

    tree[++cnt].data = val;
    tree[cnt].size = 1;
    tree[cnt].fa = f;

    if (val < tree[f].data)
    {
        tree[f].l = cnt;
    }
    else
    {
        tree[f].r = cnt;
    }
}

int main()
{

    return 0;
}
