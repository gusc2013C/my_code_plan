#include <bits/stdc++.h>

using namespace std;

string a,b;
int na,nb;

int main()
{
    freopen("longest.in","r",stdin);
    freopen("longest.out","w",stdout);

    cin >> na;
    cin >> a;
    cin >> nb;
    cin >> b;

    if (a == b)
    {
        cout << -1 << endl;
        return 0;
    }
    else if (na != nb)
    {
        cout << max(na,nb);
        return 0;
    }
    else
    {
        cout << na;
        return 0;
    }
    return 0;
}
