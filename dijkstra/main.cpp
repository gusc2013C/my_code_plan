#include <bits/stdc++.h>

using namespace std;

int dist[1005];
bool flag[1005];
int graph[1005][1005];

int dijkstra()
{
    flag[1] = true;

    memset(dist,0x7fffffff,sizeof(graph));

    for (int i = 2;i <= n;i++)
    {
        dist[i] = graph[1][i];
    }

    for (int i = 2; i <= n;i++)
    {
        int min_p = 0;
        int min_v = 0x7ffffff;

        for (int j = 2;j <= n;j++)
        {
            if (flag[j] == false&&dist[j] < min_v)
            {
                min_p = j;
                min_v = dist[j];
            }
        }

        flag[min_p] = true;

        for (int j = 2;j <= n;j++)
        {
            if (flag[j] == false&&dist[min_p]+graph[min_p,j] < dist[j])
            {
                dist[j] = dist[min_p] + graph[min_p,j];
            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
