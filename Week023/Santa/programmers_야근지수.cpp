#include <string>
#include <vector>
#include <queue> 

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq(works.begin(), works.end()); 

    while(n > 0)
    {
        int temp = pq.top();
        
        if(temp <= 0)
        {
            break;
        }
        
        pq.pop();
        pq.push(--temp);
        n--;
    }
    
    while(!pq.empty())
    {
        int temp = pq.top();
        answer += temp * temp;
        pq.pop();
    }
    return answer;
}