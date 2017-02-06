#include <bits/stdc++.h>

using namespace std;

int n,m;
string a;
long long  f[45][10];

int main()
{
    cin >> n >> m;
    cin >> a;

    for (int i = 1;i <= n;i++)
    {
        stringstream temp;
        temp << a.substr(0,i);
        temp >> f[i][0];

        #ifdef D
            cout  << f[i][0] << "temp!" << endl;
        #endif // D
    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            for (int k = 1;k < i;k++)
            {
                stringstream temp;
                temp << a.substr(k,i-k);
                int a;
                temp >> a;

                f[i][j] = max(f[i][j],f[k][j-1] * a);

                #ifdef D
                    cout << f[i][j] << " " << a << endl;
                #endif // D
            }
        }
    }

    cout << f[n][m];

    return 0;
}

