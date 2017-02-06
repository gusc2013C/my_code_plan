#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

int n;
int turn;

int main()
{
    cin >> n;

    turn = 0;  // 0北 1 东 2 南 3 西
    int x = 0;
    int y = 0;

    for (int i = 1;i <= n;i++)
    {
        string a;

        cin >> a;

        if (isalpha(a[0]))
        {
            if (a[0] == 'l')
            {
                turn--;
                if (turn < 0)
                {
                    turn = 3;
                }
            }
            if (a[0] == 'r')
            {
                turn++;
                if (turn > 3)
                {
                    turn = 0;
                }
            }
        }
        else
        {
            stringstream aa;

            int temp;

            aa << a;

            aa >> temp;

            if (turn == 0)
            {
                y += temp;
            }
            else if (turn == 1)
            {
                x += temp;
            }
            else if (turn == 2)
            {
                y -= temp;
            }
            else if (turn == 3)
            {
                x -= temp;
            }

            cout << "(" << x << "," << y << ")" << endl;
        }

    }
}

