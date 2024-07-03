#include <string>
#include <vector>
#include <climits>
#include <algorithm> 
#include <deque> 

using namespace std;

deque<int> dq; 

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    
    for(int idx = 0; idx < stones.size(); ++idx)
    {
        if(!dq.empty() && dq.front() <= idx - k) 
        {
            dq.pop_front();
        }
        
        while(!dq.empty() && stones[dq.back()] <= stones[idx])
        {
            dq.pop_back();
        }
        
        dq.push_back(idx);
        
        if(idx >= k -1)
        {
            answer = answer < stones[dq.front()] ? answer : stones[dq.front()];
        }
    }
    
    return answer;
}