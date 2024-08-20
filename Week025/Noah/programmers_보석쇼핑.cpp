#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, int(gems.size())};
    
    map<string, int> m;
    
    for(int i = 0; i < gems.size(); ++i){
        m[gems[i]] = 0;
    }
    
    int total_type = m.size();
    int l = 0, r = 0;
    int cur_types = 0;
    
    while(true){
        if(cur_types == total_type){
            if(r - l < answer[1] - answer[0]){
                answer[0] = l;
                answer[1] = r;
            }
            
            if(m[gems[l]] > 1){
                m[gems[l]]--;
            }else{
                m[gems[l]]--;
                cur_types--;
            }
            
            l++;
        }else{
            if(r == gems.size()){
                break;
            }
            
            if(m[gems[r]] == 0){
                cur_types++;
            }
            
            m[gems[r]]++;
            r++;
        }
    }
    
    answer[0]++;
    
    return answer;
}