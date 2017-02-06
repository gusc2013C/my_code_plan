#include <bits/stdc++.h>
//#define D

using namespace std;

struct zt
{
    int dia;
    int x;
    int y;
    int time;
};
struct pos
{
    int x,y;
};

int t;
pos dir[5];

zt make(int dia,int x,int y,int time)
{
    zt temp;
    temp.dia = dia;
    temp.x = x;
    temp.y = y;
    temp.time = time;
    return temp;
}

int main()
{
    cin >> t;

    dir[1].x = 0; dir[1].y = -1;
    dir[2].x = 0; dir[2].y = +1;
    dir[3].x = -1; dir[3].y = 0;
    dir[4].x = +1; dir[4].y = 0;


    for (int x = 1;x <= t;x++)
    {
        int r,c,k;
        char m[205][205];
        pos st;
        queue<zt> q;
        bool flag[40][205][205];
        pos tp[15];
        int point = 0;
        bool fin = false;

        memset(flag,0,sizeof(flag));

        for (int i = 0;i <= 205;i++)
        {
            for (int j = 0;j <= 205;j++)
            {
                m[i][j] = '#';
            }
        }

        cin >> r >> c >> k;

        for (int i = 1;i <= r;i++)
        {

            for (int j = 1;j <= c;j++)
            {
                cin >> m[i][j];
                if (m[i][j] == 'S')
                {
                    st.x = i;
                    st.y = j;
                }
                else if (m[i][j] == '$')
                {
                    tp[++point].x = i;
                    tp[point].y = j;
                }
            }
        }

        zt temp;
        temp = make(0,st.x,st.y,0);
        flag[0][st.x][st.y] = true;

        q.push(temp);

        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int dia = q.front().dia;
            int time = q.front().time;

            #ifdef D
                cout << "x" << x << "y" << y << "dia" << dia << "time" << time << " " << m[x][y] << endl;
            #endif // D

            if (dia == (1 << k) - 1 && m[x][y] == 'E')
            {
                cout << time << endl;
                fin = true;
                break;
            }

            for (int i = 1;i <= 4;i++)
            {
                if ((m[x+dir[i].x][y+dir[i].y] == '.' || m[x+dir[i].x][y+dir[i].y] == 'S' || m[x+dir[i].x][y+dir[i].y] == 'E')&& !flag[dia][x+dir[i].x][y+dir[i].y])
                {
                    flag[dia][x+dir[i].x][y+dir[i].y] = true;

                    q.push(make(dia,x+dir[i].x,y+dir[i].y,time+1));
                }

                else if (m[x+dir[i].x][y+dir[i].y]  <= '4'  && m[x+dir[i].x][y+dir[i].y] >= '0')
                {
                    int temp = m[x+dir[i].x][y+dir[i].y] - '0';

                    int tdia = dia | 1 << temp;

                    if (!flag[tdia][x+dir[i].x][y+dir[i].y])
                    {
                        q.push(make(tdia,x+dir[i].x,y+dir[i].y,time+1));
                        flag[tdia][x+dir[i].x][y+dir[i].y] = true;
                    }
                }
                else if (m[x+dir[i].x][y+dir[i].y] == '$')
                {
                    for (int j = 1;j <= point;j++)
                    {
                        if (!flag[dia][tp[j].x][tp[j].y])
                        {
                            flag[dia][tp[j].x][tp[j].y] = true;
                            q.push(make(dia,tp[j].x,tp[j].y,time+1));
                        }
                    }
                }
            }

            q.pop();
        }

        if (!fin) cout << "oop!" << endl;

    }

    return 0;
}
