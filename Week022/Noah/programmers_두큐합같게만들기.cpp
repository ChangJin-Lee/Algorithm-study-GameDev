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

// 투포인터 풀이
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum = 0;
    long long targetSum = 0;
    
    vector<int> v;
    
    for(int i = 0; i < queue1.size(); ++i){
        v.push_back(queue1[i]);
        targetSum += queue1[i];
    }
    
    sum = targetSum;
    
    for(int i = 0; i < queue2.size(); ++i){
        v.push_back(queue2[i]);
        targetSum += queue2[i];
    }
    
    targetSum /= 2;

    int l = 0, r = queue1.size() - 1;
    
    while(sum != targetSum){
        if(sum > targetSum){
            sum -= v[l];
            l++;
            answer++;
        }else{
            r++;
            sum += v[r % v.size()];
            answer++;
        }
        
        if(answer >= queue1.size() * 3){
            return -1;
        }
    }
    
    return answer;
}