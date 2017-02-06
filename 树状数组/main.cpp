#include <bits/stdc++.h>

using namespace std;

vector <int> a;
int n;

class tree
{
private:
    vector<int> f;

    int lowbit(int a)
    {
        return a & (-a);
    }
public:
    tree()
    {
        f.clear();
    }

    void change(int a,int v)
    {
        for (int i = a;i <= n;i += lowbit(i))
        {
            f[i] += v;
        }
    }

    int sum(int a)
    {
        int res = 0;

        for (int i = a;i > 0;i -= lowbit(i))
        {
            res += f[i];
        }

        return res;
    }
};

int main()
{
    return 0;
}
