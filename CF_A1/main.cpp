#include <iostream>

using namespace std;

int main()
{
    long long n,m,a;
    cin>>n>>m>>a;
    long long sum= (n/a+(n%a+a-1)/a) * (m/a+(m%a+a-1)/a);
    cout<< sum <<endl;
    return 0;
}
