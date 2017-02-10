#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(unsigned(time(NULL)));

    int n,m,index;
    string filename = "longest";
    stringstream change;
    string index_s;

    cin >> n >> m >> index;

    change << index;
    change >> index_s;

    filename = filename + index_s + ".in";


    freopen(filename.c_str(),"w",stdout);

    printf("%d\n",n);

    for (int i = 1;i <= n;i++)
    {
        printf("%c",char(rand()%26)+'a');
    }

    printf("\n%d\n",m);

    for (int i = 1;i <= m;i++)
    {
        printf("%c",char(rand()%26)+'a');
    }

    return 0;
}
