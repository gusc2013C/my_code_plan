#include <iostream>

using namespace std;

struct glass
{
    int a;
    int b;
    int dep;
    int fa;
};

glass q[1000];
int l = -1;
int r = -1;
bool f[1000][1000];

int a,b,ans;

void print(int a)
{
    if (a == -1) return;
    print(q[a].fa);
    cout << q[a].a << " "<< q[a].b << endl;
}

int main()
{
    cin >> a >> b >> ans;

    q[++r].a = 0; q[r].b = 0; q[r].dep = 0; q[r].fa = -1;

    while (l < r)
    {
        l++;

        int va = q[l].a;
        int vb = q[l].b;
        int vdep = q[l].dep;

        if (va + vb == ans)
        {
            cout << vdep;
            print(l);
            return 0;
        }

        if (!f[a][vb])  // 倒满a
        {
            r++;
            q[r].a = a;
            q[r].b = vb;
            q[r].dep = vdep + 1;
            q[r].fa = l;
            f[a][vb] = true;
        }
        if (!f[va][b])   // 倒满b
        {
            r++;
            q[r].a = va;
            q[r].b = b;
            q[r].dep = vdep + 1;
            q[r].fa = l;
            f[va][b] = true;
        }
        //##########################################
        if (va > 0 && !f[0,vb]) // 倒空a
        {
            r++;
            q[r].a = 0;
            q[r].b = vb;
            q[r].dep = vdep + 1;
            q[r].fa = l;
            f[0][vb] = true;
        }
        if (vb > 0 && !f[va,0]) // 倒空b
        {
            r++;
            q[r].a = va;
            q[r].b = 0;
            q[r].dep = vdep + 1;
            q[r].fa = l;
            f[va][0] = true;
        }
        //########################################## 把b倒给a
        int ta = va;
        int tb = vb;

        if (va + vb <= a)
        {
            ta = va + vb;
            tb = 0;
        }
        else if (va + vb > a)
        {
            ta = a;
            tb = vb - (a - va);
        }

        if (!f[ta][tb])
        {
            r++;
            q[r].a = ta;
            q[r].b = tb;
            q[r].dep = vdep + 1;
            q[r].fa = l;
            f[ta][tb] = true;
        }
        //########################################### 把a倒给b
        ta = va;
        tb = vb;

        if (va + vb <= b)
        {
            tb = va + vb;
            ta = 0;
        }
        else if (va + vb > b)
        {
            tb = b;
            ta = va - (b - vb);
        }

        if (!f[ta][tb])
        {
            r++;
            q[r].a = ta;
            q[r].b = tb;
            q[r].dep = vdep + 1;
            q[r].fa = l;
            f[ta][tb] = true;
        }
    }

    return 0;
}
