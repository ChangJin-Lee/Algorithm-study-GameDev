#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int cnt = 1;
    
    for(char c = 'A'; c <= 'Z'; c++){
        string str = "";
        str += c;
        m[str] = cnt++;
    }
    
    string str = "";
    
    for(int i = 0; i < msg.length(); ++i){
        str += msg[i];
        if(m[str] == 0){
            m[str] = cnt++;
            str = str.substr(0, str.length() - 1);
            answer.push_back(m[str]);
            str = "";
            i--;
        }
    }
    answer.push_back(m[str]);    
    
    return answer;
}