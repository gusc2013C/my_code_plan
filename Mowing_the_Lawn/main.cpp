#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[100005];
long long ans;
int m;
int f[100005];

struct node
{
    int a;
    int index;
};

class bhq
{
private:
    node q[100005];
    int head;
    int tail;

public:
    bhq()
    {
        memset(q,0,sizeof(q));
        head = 1;
        tail = 0;
    }

    void push(int a,int index)
    {
        while (q[tail].a > a && tail >= head)
        {
            tail--;
        }

        q[++tail].a = a;
        q[tail].index = index;

        while (q[head].index < index - k  && head < tail)
        {
            head++;
        }
    }

    int front()
    {
        return q[head].a;
    }
};

bhq getsmaller;

int main()
{
    scanf("%d %d",&n,&k);

    getsmaller.push(0,0);

    for (int i = 1; i <= n ;i++)
    {
        scanf("%d",&a[i]);
        ans += a[i];
    }

    m = __INT32_MAX__;

    for (int i = 1; i <= n;i++)
    {
        f[i] = getsmaller.front() + a[i];
        getsmaller.push(a[i],i);
        if (n - i <= k) m = min(m,f[i]);

        //printf("%d\n",f[i]);
    }

    printf("%d",ans - m);

    return 0;
}
