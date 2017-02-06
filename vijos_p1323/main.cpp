#include <bits/stdc++.h>

using namespace std;

struct node
{
    int work;
    int na[4];
    int pos;
};

char cp[105];
bool flag[12][12][12][102];
int n;
int ga,gb,gc;

node make(int work,int na1,int na2,int na3,int pos);

int main()
{
    //queue<char> iron;
    cin >> n;

    for (int i = 1;i <= n;i++)
    {
        cin >> cp[i];
        //iron.push(cp[i]);
        if (cp[i] == 'A')
        {
            ga++;
        }
        else if (cp[i] == 'B')
        {
            gb++;
        }
        else
        {
            gc++;
        }
    }

    if (n <= 10)
    {
        cout << (ga > 0) + (gb > 0) + (gc > 0);
        return 0;
    }

    queue<node> q;

    int ma = 0;
    int mb = 0;
    int mc = 0;

    for (int i = 1;i <= 10;i++)
    {
        char temp = cp[i];
        //temp = iron.front();

        if (temp == 'A')
        {
            ma++;
        }
        else if (temp == 'B')
        {
            mb++;
        }
        else
        {
            mc++;
        }
    }

    q.push(make(0,ma,mb,mc,10));

    while (!q.empty())
    {
        int work = q.front().work;
        int a = q.front().na[1];
        int b = q.front().na[2];
        int c = q.front().na[3];
        int pos = q.front().pos;

        //cout << work << " " << a << " " << b << " " << c << " " << pos << endl;

        if (pos == n && a == 0 && b == 0 && c == 0)
        {
            cout << work;
            return 0;
        }

        if (a > 0)
        {
            int aa = 0;
            int bb = 0;
            int cc = 0;

            for (int i = pos+1;i <= min(pos + a,n);i++)
            {
                char temp = cp[i];

                if (temp == 'A')
                {
                    aa++;
                }
                else if (temp == 'B')
                {
                    bb++;
                }
                else
                {
                    cc++;
                }

            }

            if (!flag[aa][bb+b][cc+c][ min(pos+a,n)])
            {
                q.push(make(work+1,aa,bb+b,cc+c,min(pos+a,n)));
                flag[aa][bb+b][cc+c][min(pos+a,n)] = true;
            }
        }

        if (b > 0)
        {
            int aa = 0;
            int bb = 0;
            int cc = 0;

            for (int i = pos+1;i <= min(pos + b,n);i++)
            {
                char temp = cp[i];

                if (temp == 'A')
                {
                    aa++;
                }
                else if (temp == 'B')
                {
                    bb++;
                }
                else
                {
                    cc++;
                }

            }

            if (!flag[aa+a][bb][cc+c][min(pos+b,n)])
            {
                q.push(make(work+1,aa+a,bb,cc+c,min(pos+b,n)));
                flag[aa+a][bb][cc+c][min(pos+b,n)] = true;
            }
        }

        if (c > 0)
        {
            int aa = 0;
            int bb = 0;
            int cc = 0;

            for (int i = pos+1;i <= min(pos + c,n);i++)
            {
                char temp = cp[i];

                if (temp == 'A')
                {
                    aa++;
                }
                else if (temp == 'B')
                {
                    bb++;
                }
                else
                {
                    cc++;
                }

            }

            if (!flag[aa+a][bb+b][cc][min(pos+c,n)])
            {
                q.push(make(work+1,aa+a,bb+b,cc,min(pos+c,n)));
                flag[aa+a][bb+b][cc][min(pos+c,n)] = true;
            }
        }

        q.pop();
    }


    return 0;
}

node make(int work,int na1,int na2,int na3,int pos)
{
    node temp;
    temp.work = work;
    temp.na[1] = na1;
    temp.na[2] = na2;
    temp.na[3] = na3;
    temp.pos = pos;
    return temp;
}
