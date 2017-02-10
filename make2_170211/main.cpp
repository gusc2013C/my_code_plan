#include <bits/stdc++.h>

using namespace std;

int n,m;

char a[4] = {'.','.','.','#'};

int sx,sy,tx,ty,xx[6],yy[6];
bool flag[205][205];
char ans[205][205];

int main()
{
    int index;
    cin >> n >> m >> index;

    string filename = "fallout";
    stringstream change;
    string index_s;

    change << index;
    change >> index_s;

    filename = filename + index_s + ".in";


    freopen(filename.c_str(),"w",stdout);

    srand(unsigned(time(NULL)));

    sx = (rand() % n) + 1;
    sy = (rand() % n) + 1;
    flag[sx][sy] = true;
    ans[sx][sy] = 'S';

    tx = (rand() % n) + 1;
    ty = (rand() % n) + 1;

    while (flag[tx][ty])
    {
        tx = (rand() % n) + 1;
        ty = (rand() % n) + 1;
    }
    ans[tx][ty] = 'T';
    flag[tx][ty] = true;

    for (int i = 1;i <= 5;i++)
    {
        int x,y;
        x = (rand() % n) + 1;
        y = (rand() % n) + 1;

        while (flag[x][y])
        {
            x = (rand() % n) + 1;
            y = (rand() % n) + 1;
        }

        ans[x][y] = i + '0';
        flag[x][y] = true;
    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (!flag[i][j])
            {
                cout << a[rand()%4];
            }
            else
            {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
