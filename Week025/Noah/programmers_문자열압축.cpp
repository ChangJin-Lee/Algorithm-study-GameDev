#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    if(s.length() == 1){
        return 1;
    }
    
    for(int i = 1; i < s.length(); ++i){
        string compressed = "";
        int cnt = 1;
        string temp = s.substr(0, i);
        
        for(int j = i; j <= s.length(); j += i){
            if(temp == s.substr(j, i)){
                cnt++;
            }else{
                if(cnt != 1){
                    compressed += to_string(cnt) + temp;
                }else{
                    compressed += temp;
                }
                
                temp = s.substr(j, i);
                cnt = 1;
            }
        }
        
        if(cnt != 1){
            compressed += to_string(cnt) + temp;
        }else{
            compressed += temp;
        }
        
        answer = min(int(compressed.length()), answer);
    }
    
    return answer;
}