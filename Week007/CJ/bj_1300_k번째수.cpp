#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, k, idx;
    int start, end, mid;
    int answer = 0;
    
    cin >> n >> k;

    start = 1;
    end = k;

    while(start<=end)
    {
        mid = (start + end) /2;

        int t = 0;
        for(int i = 1; i < n+1; i++)
            t += min(mid/i, n);
        
        if(t >= k)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << answer;
}

