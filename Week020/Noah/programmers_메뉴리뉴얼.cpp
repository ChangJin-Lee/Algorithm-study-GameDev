#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> comb;

void dfs(string &order, int &len, string temp, int idx){
    if(temp.length() == len){
        comb[temp]++;
        return;
    }
    
    for(int i = idx; i < order.length(); ++i){
        dfs(order, len, temp + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int len : course){
        for(string order : orders){
            sort(order.begin(), order.end());
            dfs(order, len, "", 0);
        }
        
        int maxCnt = 0;
    
        for(auto item : comb){
            maxCnt = max(maxCnt, item.second);
        }
        
        for(auto item : comb){
            if(maxCnt < 2){
                break;
            }else if(comb[item.first] == maxCnt){
                answer.push_back(item.first);
            }
        }
        
        comb.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}