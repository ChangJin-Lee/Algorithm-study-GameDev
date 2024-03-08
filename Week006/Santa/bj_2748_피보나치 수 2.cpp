#include <iostream>

using namespace std;

long arr[91];

long fibo(long n)
{
    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return 1;
    }

    if(arr[n] != 0) 
    {
        return arr[n];
    }

    return arr[n] = fibo(n - 1) + fibo(n - 2);
}


int main ()
{
    long n = 0;

    cin >> n; 

    cout << fibo(n);

    return 0;
}