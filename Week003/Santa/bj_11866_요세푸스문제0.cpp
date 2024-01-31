#include <iostream>
#include <queue>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std; 

int main()
{
    fastTime;

    queue <int> myQueue;
    queue <int> resultQueue;

    int n, k, idx = 0;

    cin >> n >> k;

    idx = 1;

    while(n--)
    {
        myQueue.push(idx++);
    }

    idx = 1;

    while(!myQueue.empty())
    {
        while(idx != k)
        {
            myQueue.push(myQueue.front());
            myQueue.pop();
            idx++;
        }

        idx = 1;

        resultQueue.push(myQueue.front());
        myQueue.pop();

    }

    cout << "<" << resultQueue.front();
    resultQueue.pop();

    while(!resultQueue.empty())
    {
        cout << ", " << resultQueue.front();
        resultQueue.pop();
    }

    cout << ">";

    return 0;
}