#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

//#define D1

using namespace std;

int tab[255][255];
int dis[255];
int n,m,ans;

bool bfs()
{
    memset(dis,0xFF,sizeof(dis));

    queue<int> q;
    q.push(1);
    dis[1] = 0;

    while (!q.empty())
    {
        int temp = q.front();

        for (int i = 1;i <= n;i++)
        {
            if (dis[i] < 0 && tab[temp][i] > 0)
            {
                q.push(i);
                dis[i] = dis[temp] + 1;
            }
        }
        q.pop();
    }

    if (dis[n] > 0) return true;
    else return false;
}

int find(int a,int flow)
{
    if (a == n)
    {
        return flow;
    }

    for (int i = 1; i <= n;i++)
    {
        int temp;


        if (tab[a][i] > 0 && dis[a] == dis[i] - 1 && (temp = find(i,min(flow,tab[a][i]))))
        {
            tab[a][i] -= temp;
            tab[i][a] += temp;
            return temp;
        }
    }

    return 0;
}

int main()
{
while(cin >> m >> n)
{
    for (int i = 1;i <= m;i++)
    {
        int a,b,c;

        cin >> a >> b >> c;

        tab[a][b] += c;
    }

    ans = 0;

    while (bfs())
    {
        #ifdef D1
            for (int i = 1;i <= n;i++)
            {
                cout << dis[i] << endl;
            }
            cout << endl;
        #endif // D1

        int temp;
        while (temp = find(1,0x7fffffff))
        {
            ans += temp;
        }


    }

    cout << ans << endl;

}

    return 0;
}
