#include <iostream>
using namespace std; 

int main()
{
    int n;
    int l = 1; 

    cin >> n;

    while(n > l)
    {
        n -= l;
        ++l;
    }

    if(l % 2 == 0)
    {
        cout << n << '/' << l + 1 - n << endl;
    }

    else
    {
        cout << l + 1 - n << '/' << n << endl;
    }

    return 0;
}