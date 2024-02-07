#include <iostream> 
#include <stack>
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std; 

int main()
{
    fastTime;

    stack<int> myStack;
    int k, n, result = 0;

    cin >> k;

    while(k--)
    {
        cin >> n;

        n == 0 ? myStack.pop() : myStack.push(n);
    }

    while(!myStack.empty())
    {
        result += myStack.top();
        myStack.pop();
    }

    cout << result;

    return 0;
}