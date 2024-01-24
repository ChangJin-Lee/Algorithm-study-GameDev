#include <iostream>
using namespace std;
#define fastTime ios::sync_withstdio(false), cin.tie(0);



int fibonacciNumber(int n)
{
    if(n == 1)
    {
        return 1;
    }

    if(n == 0)
    {
        return 0;
    }

    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}



int main()
{
    int n = 0;

    cin >> n;

    cout << fibonacciNumber(n);
}