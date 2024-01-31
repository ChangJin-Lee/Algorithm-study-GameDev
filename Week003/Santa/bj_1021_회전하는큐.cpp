#include <iostream>
#include <deque> 
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    deque <int> myDeque;
    int n, m, num, countNum = 0;

    cin >> n >> m;

    for(int idx = 1; idx <= n; idx++)
    {
        myDeque.push_back(idx);
    }

    while(m--)
    {
        cin >> num;
        
        n = 0;

        while(num != myDeque[n])
        {  
            n++;
        }

        // if requested value's index is greater than median index, pop from back  
        if(n > myDeque.size() / 2)
        {
            while(num != myDeque.front())
            {
                myDeque.push_front(myDeque.back());
                myDeque.pop_back();
                countNum++;
            }
        }
        else
        {
            while(num != myDeque.front())
            {
                myDeque.push_back(myDeque.front());
                myDeque.pop_front();
                countNum++;
            }
        }
    
        myDeque.pop_front();
    }
    
    cout << countNum;

    return 0;
}