#include <bits/stdc++.h>

#define maxn 10005
#define INF 1<<30

using namespace std;


int n,m,s,t;

struct edge
{
    int from,to,cap,flow;
};


struct ek
{
    int p[maxn],a[maxn];

    vector<edge> edges;
    vector<int>g[maxn];

    ek()
    {
        for (int i = 0;i <= n;i++)g[i].clear();
        edges.clear();
    }

    void add(int from,int to,int cap)
    {
        edges.push_back((edge){from, to, cap, 0});//正向边
        edges.push_back((edge){to, from, 0, 0});  //反向边
        int m = edges.size();
        g[from].push_back(m-2);                   //正向边
        g[to].push_back(m-1);                     //反向边
    }

    int bfs(int s,int t)
    {
        int flow = 0;

        while (1)
        {
            queue<int> q;
            q.push(s);

            memset(a,0,sizeof(a));
            a[s] = INF;

            while (!q.empty())
            {
                int x = q.front();
                q.pop();

                for (int i = 0;i < g[x].size();i++)
                {
                    edge& e = edges[g[x][i]];

                    if (!a[e.to] && e.flow < e.cap)
                    {
                        p[e.to] = g[x][i];
                        a[e.to] = min(a[x],e.cap - e.flow);
                        q.push(e.to);
                    }
                }

                if (a[t]) break;
            }

            if (!a[t]) break;

            flow += a[t];

            for (int i = t;i != s;i = edges[p[i]].from)
            {
                edges[p[i]].flow += a[t];
                edges[p[i]^1].flow -= a[t];
            }
        }

        return flow;
    }
};

ek work;

int main()
{
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m;i++)
    {
        int u,v,w;

        cin >> u >> v >> w;

        work.add(u,v,w);
    }

    cout << work.bfs(s,t);

    return 0;
}
