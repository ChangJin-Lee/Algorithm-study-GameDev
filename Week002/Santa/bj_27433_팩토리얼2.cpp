#include <iostream>
#define fastTime ios::sync_withstdio(false), cin.tie(0)

using namespace std; 

long long factorial (long long n)
{
    if(n <= 1)
    {
        return 1;
    }

    return factorial(n - 1) * n;
}


int main()
{
    int n = 0;

    cin >> n;

    cout << factorial(n);

    return 0;
}