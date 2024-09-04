#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s){
        return {-1};
    }
    
    int div = s / n;
    int extra = s % n;
    
    for(int i = 0; i < n; ++i){
        answer.push_back(div);
    }
    
    for(int i = 0; i < extra; ++i){
        answer[i]++;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}