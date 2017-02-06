#include <bits/stdc++.h>

using namespace std;

struct node
{
    int a;
    int index;
};

int n,k;
int ar[1000005];

class bhq
{
private:
    node q[1000005];
    int head,tail;
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

        while (q[head].index < (index - k + 1) && head < tail)
        {
            head++;
        }

    }

    int front(void)
    {
        return q[head].a;
    }
};

class shq
{
private:
    node q[1000005];
    int head,tail;
public:
    shq()
    {
        memset(q,0,sizeof(q));
        head = 1;
        tail = 0;
    }
    void push(int a,int index)
    {
        while (q[tail].a < a && tail >= head)
        {
            tail--;
        }

        q[++tail].a = a;
        q[tail].index = index;

        while (q[head].index < (index - k + 1) && head < tail)
        {
            head++;
        }

    }

    int front(void)
    {
        return q[head].a;
    }
};

shq getbigger;
bhq getsmaller;

int main()
{
    cin >> n >> k;

    for (int i = 1;i <= n;i++)
    {
        cin >> ar[i];
    }

    for (int i = 1;i <= n;i++)
    {
        getsmaller.push(ar[i],i);
        if (i >= k) cout << getsmaller.front() << " ";
    }

    cout << endl;

    for (int i = 1;i <= n;i++)
    {
        getbigger.push(ar[i],i);
        if (i >= k) cout << getbigger.front() << " ";
    }

    cout << endl;
    return 0;
}
