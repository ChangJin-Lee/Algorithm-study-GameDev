#include <iostream>
#include <cmath>
#define fastTime ios::sync_withstdio(false), cin.tie(0)

using namespace std; 

int blank = 0;

void cantor (int n)
{
    if(n == 0)
    {
        cout << '-';
        return;
    }
    
    cantor(n - 1);

    blank = pow(3, n - 1);

    for(int idx = 0; idx < blank; idx++)
    {
        cout << ' ';
    }

    cantor(n - 1);
}

int main()
{
    int n = 0; 

    while(cin >> n)
    {
        cantor(n);
        cout << '\n';
    }

    return 0;
}