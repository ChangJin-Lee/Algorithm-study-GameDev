#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    
    while(!progresses.empty()){
        for(int i = 0; i < progresses.size(); ++i){
            progresses[i] += speeds[i];
        }
        if(progresses.front() >= 100){
            while(progresses.front() >= 100){
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                cnt++;
                if(progresses.empty()){
                    break;
                }
            }
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    
    return answer;
}