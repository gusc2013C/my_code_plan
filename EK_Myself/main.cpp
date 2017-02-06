#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

struct edge
{
    int from,to,cap;
};

vector <edge> e;
bool used[N];
int s,t;
int n,m;
int ans;
vector <int>g[N];
bool finish = true;

void add(int from,int to,int cap)
{
    e.push_back((edge){from,to,cap});
    e.push_back((edge){to,from,0});
    int m = e.size();
    g[from].push_back(m-2);
    g[to].push_back(m-1);
}

int dfs(int a,int flow)
{
    if (a == t)
    {
        finish = true;
        ans += flow;
        return flow;
    }

    int temp;

    for (int i = 0;i < g[a].size();i++)
    {
        edge&ed = e[g[a][i]];

        if (!used[ ed.to ] && ed.cap)
        {
            used[ ed.to ]  = true;
            temp = dfs(ed.to,min(flow,ed.cap));

            if (finish)
            {
                e[g[a][i]].cap -= temp;
                e[g[a][i] ^ 1].cap += temp;
                return temp;
            }
        }
    }

    return 0;
}


int main()
{
    cin >> n >> m >> s >> t;

    for (int i = 1;i <= m;i++)
    {
        int u,v,c;

        cin >> u >> v >> c;

        add(u,v,c);
    }

    for (;finish;)
    {
        finish = false;
        memset(used,0,sizeof(used));
        used[s] = true;
        dfs(s,0x7fffffff);
        #ifndef ONLINE_JUDGE
            cout << "oop!" << endl;
        #endif // ONLINE_JUDGE
    }

    cout << ans;

    return 0;
}
