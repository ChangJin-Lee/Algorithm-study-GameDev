#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum1 = 0, sum2 = 0;
    long long targetSum = 0;
    queue<int> q1, q2;
    
    for(int i = 0; i < queue1.size(); ++i){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    targetSum = (sum1 + sum2) / 2;
    
    while(!q1.empty() && !q2.empty()){
        if(sum1 == targetSum){
            return answer;
        }
        
        if(answer > queue1.size() * 3){
            return -1;
        }
        
        if(sum1 > targetSum){
            sum1 -= q1.front();
            sum2 += q1.front();
            
            q2.push(q1.front());
            q1.pop();
        }else{
            sum1 += q2.front();
            sum2 -= q2.front();
            
            q1.push(q2.front());
            q2.pop();
        }
        
        answer++;
    }
    
    return -1;
}