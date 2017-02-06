
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    /*int a,b,c;

    cin >> a;
    cin.clear();

    cin >> b  >> c;

    cout << a << " " << b << " " << c <<" ";
    return 0;*/

    //char s[100],t[100];

//char b;

    //cin.getline(s,100,'b');
    //cin.clear();
    //cin.getline(t,5);
    //cin.clear();
    //cin.get(b);

    //cout << s << endl;
    //ascout << int(b);

    int a;

    char c;

    c = cin.get();

    while (c != -1)
    {
        cout << char(c);
        c = cin.get();
    }
}
