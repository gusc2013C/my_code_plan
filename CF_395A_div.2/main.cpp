#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if (a < b)
    {
        int temp = b;
        b = a;
        a = temp;
    }

    while (b)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }

    return a;
}

int gongbei(int a,int b)
{
    return (a*b) / gcd(a,b);
}

int main()
{
    int n,m,z;

    while (cin >> n >> m >> z)
    {
        cout << z / gongbei(n,m) << endl;
    }

    return 0;
}
