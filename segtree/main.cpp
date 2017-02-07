#include <bits/stdc++.h>

using namespace std;



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

    tree[x] = min(tree[x+x],tree[x+x+1]);
}

int query(int x,int l,int r,int a,int b)
{
    if (l == a && r == b)
    {
        return tree[x];
    }

    int mid = (l + r) >> 1;

    if (b <= mid) return query(x+x,l,mid,a,b)
    else if (a > mid) return query(x+x+1,mid+1,r,a,b)
    else return min(query(x+x,l,mid,a,mid),query(x+x+1,mid+1,r,mid+1,b));
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
