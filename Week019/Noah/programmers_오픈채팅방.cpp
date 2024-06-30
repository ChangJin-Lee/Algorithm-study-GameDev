#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userInfo;
    vector<pair<string, string>> chat;
    
    for(auto command : record){
        istringstream iss(command);
        string s1, s2, s3;
        iss >> s1 >> s2 >> s3;
        
        if(s1 != "Leave"){
            userInfo[s2] = s3;
        }
        
        if(s1 != "Change"){
            chat.push_back({s1, s2});
        }
    }
    
    for(auto c : chat){
        string temp = "";
        
        if(c.first == "Enter"){
            temp = userInfo[c.second] + "님이 들어왔습니다.";
        }else if(c.first == "Leave"){
            temp = userInfo[c.second] + "님이 나갔습니다.";
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}