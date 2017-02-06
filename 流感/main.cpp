#include <iostream>
//#include <queue>
#include <map>

#define DEBUG

using namespace std;

struct pos
{
    int x;
    int y;
    int dep;
};

pos q[10005];
char m[105][105];
int n;
int ma;
int head = 0;
int tail = 0;

void pop();
void push(int a,int b,int dep);
pos fr();
//map<pos,bool> flag;

int main()
{
    //char c;
    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            cin >> m[i][j];

            if (m[i][j] == '@')
            {
                push(i,j,0);
            }
        }
    }
    cin >> ma;

    while (head < tail)
    {
        pop();

        if (fr().dep > ma)
        {
            cout << head - 1 << endl;
            return 0;
        }

        pos t1,t2,t3,t4;

        t1.x = fr().x-1; t1.y = fr().y;
        t2.x = fr().x+1; t2.y = fr().y;
        t3.x = fr().x; t3.y = fr().y-1;
        t4.x = fr().x; t4.y = fr().y+1;

        if ((fr().x-1 > 0 && !flag[t1]) && (m[fr().x-1][fr().y] == '.'))
        {
            push(fr().x-1,fr().y,fr().dep+1);
        }
        if (fr().x+1 <= n && !flag[t2] && m[fr().x+1][fr().y] == '.')
        {
            push(fr().x+1,fr().y,fr().dep+1);
        }
        if (fr().y-1 > 0 && !flag[t3] && m[fr().x][fr().y-1] == '.')
        {
            push(fr().x,fr().y-1,fr().dep+1);
        }
        if (fr().y+1 <= n && !flag[t4] && m[fr().x][fr().y+1] == '.')
        {
            push(fr().x,fr().y+1,fr().dep+1);
        }
    }


    return 0;
}
void pop()
{
    head++;
}

void push(int a,int b)
{
    pos temp;

    temp.x = a;
    temp.y = b;

    tail++;
    q[tail] = temp;
    flag[temp] = true;
}
pos fr()
{
    return q[head];
}
