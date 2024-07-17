#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long left = 1; 
    long long right = (long) times.back() * n;
    long long mid = 0;
    long long count = 0;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        count = 0; 

        for(int i = 0; i < times.size(); ++i)
        {
            count += mid / times[i];
        }
        if(count >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else 
        {
            left = mid + 1;
        }
    }
    return answer;
}
