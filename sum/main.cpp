#include <bits/stdc++.h>

using namespace std;

int tree[400005];
int a[400005];
int n,m;

void make(int x,int l,int r)
{
    if (l == r)
    {
        tree[x] = a[l];
        return;
    }

    int mid = (l + r) >> 1;

    make(x+x,l,mid);
    make(x+x+1,mid+1,r);

    tree[x] = max(tree[x+x] , tree[x+x+1]);
}

void change(int x,int l ,int r,int pos,int val)
{
    if (l == r)
    {
        tree[x] = val;
        return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
    {
        change(x+x,l,mid,pos,val);
    }
    else
    {
        change(x+x+1,mid+1,r,pos,val);
    }

    tree[x] = max(tree[x+x] , tree[x+x+1]);
}

int query(int x,int l,int r,int a,int b)
{
    if (l == a && r == b)
    {
        return tree[x];
    }

    int mid = (l + r) >> 1;

    if (b <= mid) return query(x+x,l,mid,a,b);
    else if (a > mid) return query(x+x+1,mid+1,r,a,b);
    else return max(query(x+x,l,mid,a,mid) , query(x+x+1,mid+1,r,mid+1,b));
}

int main()
{
    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }

    cin >> m;

    make(1,1,n);

    for (int i = 1;i <= m;i++)
    {
        int x,y,z;

        scanf("%d %d %d",&x,&y,&z);

        if (x == 1)
        {
            change(1,1,n,y,z);
        }
        else
        {
            printf("%d\n",query(1,1,n,y,z));
        }
    }

    return 0;
}
