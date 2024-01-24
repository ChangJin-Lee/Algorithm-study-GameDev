#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int Fibonacci(int n);

// f(n) = f(n-1) + f(n-2) (n>=2)
int main()
{
    fastcpp;
    int input = 0;
    cin >> input;
    cout << Fibonacci(input);
}

int Fibonacci(int n)
{
    if ( n == 0)
        return 0;
    else if ( n == 1)
        return 1;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}