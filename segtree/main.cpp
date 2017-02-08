#include <bits/stdc++.h>

using namespace std;

int add[100005];

void change(int x,int l ,int r,int pos,int val)
{
    if (l == r)
    {
        tree[x] = val;
        return;
    }
    if (add[x] != 0) push_down(x);

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

void push_down(int x)
{
	tree[x + x] += add[x];
	tree[x + x + 1] += add[x];
	add[x + x] += add[x];
	add[x + x + 1] += add[x];
	add[x] = 0;
}


void change(int x,int l,int r,int a,int b,int val)
{
    if (l == a && r == b)
    {
        tree[x] += val;
        add[x] += val;
        return;
    }

    if (add[x] != 0) push_down(x);

    int mid = (l + r) >> 1;

    if (b <= mid) change(x+x,l,mid,a,b,val);
    else if (a > mid) change(x+x+1,mid+1,r,a, b,val)
    else
    {
        change(x+x,l,mid,a,mid,val);
        change(x+x+1,mid+1,r,mid+1,b,val);
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
    if (added[x] != 0) push_down(x);

    if (b <= mid) return query(x+x,l,mid,a,b)
    else if (a > mid) return query(x+x+1,mid+1,r,a,b)
    else return min(query(x+x,l,mid,a,mid),query(x+x+1,mid+1,r,mid+1,b));
}

int main()
{

    return 0;
}
