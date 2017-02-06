#include<iostream>
#include<cstring>
#include<map>

using namespace std;

struct binary
{
    char l;
    char r;
    char data;

    binary()
    {
        l = '0';
        r = '0';
        data = '0';
    }
};

binary tree[27];
map<char,int> turn;

void search(int a);

int main()
{
    int n;
    cin >> n;



    for (int i = 1;i <= n;i++)
    {
        char c;
        cin >> c;
        turn[c] = i;
        tree[i].data = c;
        cin >> tree[i].l >> tree[i].r;
        if (tree[i].l == '*') tree[i].l = '0';
        if (tree[i].r == '*') tree[i].r = '0';
    }

    search(1);

    return 0 ;
}

void search(int a)
{
    cout << tree[a].data;

    if (tree[a].l != '0') search(turn[tree[a].l]);
    if (tree[a].r != '0') search(turn[tree[a].r]);
}
