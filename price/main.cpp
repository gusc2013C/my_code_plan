#include <bits/stdc++.h>

using namespace std;

int graph[1005][1005];
int num[1005];

void dfs(int a)
{
    if (num[a] > 0) return;

    for(int i = 1;i <= n;i++)
    {
        if(graph[i][a])
        {
            dfs(i);
            if (num[i]+1 > num[a]) num[a] = num[i] + 1;
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
