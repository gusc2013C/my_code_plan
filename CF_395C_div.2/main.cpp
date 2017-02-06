#include<bits/stdc++.h>

using namespace std;

struct edge
{
    int from;
    int to;
};

vector<edge> input;
int f[100005];
int c[100005];
int n;

int main()
{
    scanf("%d",&n);

    for (int i = 1;i <= n - 1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        edge temp;

        temp.from = a;
        temp.to = b;

        input.push_back(temp);
    }

    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&c[i]);
    }

    int cnt = 0;

    for (int i = 0;i <= n-2;i++)
    {
        if (c[input[i].from]== c[input[i].to]) continue;

        f[input[i].from]++;
        f[input[i].to]++;

        cnt++;
    }

    //cout << cnt << endl;

    for (int i = 1;i <= n;i++)
    {
        //cout << f[i] << endl;

        if (f[i] == cnt)
        {
            cout << "YES" << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
