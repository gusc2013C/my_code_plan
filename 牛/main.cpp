#include <iostream>
#include <queue>

//#define DEBUG

using namespace std;

struct step
{
    int pos;
    int dep;
};

queue<step> q;
bool f[100005];

int n;
int k;

int main()
{
    cin >> n >> k;

    step temp;

    temp.dep = 0;
    temp.pos = n;

    q.push(temp);
    f[n] = true;

    while (!q.empty())
    {
        #ifdef DEBUG
            cout << q.front().pos << " " << q.front().dep << "pop"<< endl;
        #endif // DEBUG

        if (q.front().pos == k)
        {
            cout << q.front().dep << endl;
            return 0;
        }

        if (q.front().pos+1 <= 100000 && !f[q.front().pos+1])
        {
            step t;
            t.dep = q.front().dep + 1;
            t.pos = q.front().pos + 1;
            f[q.front().pos+1] = true;
            q.push(t);
            #ifdef DEBUG
                cout << t.pos << " " << t.dep << "pusha" << endl;
            #endif // DEBUG
        }
        if (q.front().pos-1 >= 0 && !f[q.front().pos-1])
        {
            step t;
            t.dep = q.front().dep + 1;
            t.pos = q.front().pos - 1;
            f[q.front().pos-1] = true;
            q.push(t);
            #ifdef DEBUG
                cout << t.pos << " " << t.dep  << "pushb" << endl;
            #endif // DEBUG
        }
        if (q.front().pos * 2 <= 100000 && !f[q.front().pos*2])
        {
            step t;
            t.dep = q.front().dep + 1;
            t.pos = q.front().pos * 2;
            f[q.front().pos * 2] = true;
            q.push(t);
            #ifdef DEBUG
                cout << t.pos << " " << t.dep  << "pushc" << endl;
            #endif // DEBUG
        }

        q.pop();
        #ifdef DEBUG
            cout << "pop!" << endl  ;
        #endif // DEBUG
    }

    return 0;
}
