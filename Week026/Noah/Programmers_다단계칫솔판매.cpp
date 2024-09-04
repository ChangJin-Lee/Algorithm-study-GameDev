#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> enr_map;
map<string, string> ref_map;

void dfs(string seller, int money){
    if(seller == "-"){
        return;
    }
    
    int div = money / 10;
    
    enr_map[seller] += money - div;
    
    if(div > 0){
        dfs(ref_map[seller], div);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); ++i){
        enr_map[enroll[i]] = 0;
        ref_map[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); ++i){
        dfs(seller[i], amount[i] * 100);
    }
    
    for(int i = 0; i < enr_map.size(); ++i){
        answer.push_back(enr_map[enroll[i]]);
    }
    
    return answer;
}