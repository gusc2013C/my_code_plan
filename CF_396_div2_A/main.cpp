#include <bits/stdc++.h>

using namespace std;

string a,b;

int main()
{
    cin >> a;
    cin >> b;

    if (a == b)
    {
        cout << -1 << endl;
        return 0;
    }
    else if (a.size() != b.size())
    {
        cout << max(a.size(),b.size());
        return 0;
    }
    else
    {
        cout << a.size();
        return 0;
    }

    return 0;
}
