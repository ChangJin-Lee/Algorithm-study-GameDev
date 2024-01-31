#include <iostream>
#include <deque>
#include <algorithm>
#include <math.h>

using namespace std; 

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    // first - ballon number, second - paper number 
    deque <pair<int, int> > balloon;
    int n, num, idx = 0;

    cin >> n;

    while(n--)
    {
        cin >> num;

        balloon.push_back(make_pair(++idx, num));
    }

    while(!balloon.empty())
    {        
        cout << balloon.front().first << ' ';

        idx = balloon.front().second;
        balloon.pop_front();

        idx < 0 ? num = 0 : num = 1;

        for(int move = num; move < abs(idx); move++)
        {
            if(idx > 0)
            {
                balloon.push_back(balloon.front());
                balloon.pop_front();
            }
            else
            {
                balloon.push_front(balloon.back());
                balloon.pop_back();
            }
        }
    }

    return 0;
}