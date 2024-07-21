#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str){
    stack<char> s;
    
    for(auto c : str){
        if(c == '('){
            s.push(c);
        }else if(s.empty()){
            return false;
        }else{
            s.pop();
        }
    }
    
    return true;
}

string changeBracket(string str){
    string changedStr = "(";
    
    for(int i = 1; i < str.length() - 1; ++i){
        if(str[i] == '('){
            changedStr += ")";
        }else{
            changedStr += "(";
        }
    }
    
    changedStr += ")";
    
    return changedStr;
}

string getBalanceStr(string p){
    string s1 = "";
    string s2 = "";
    stack<char> s;
    
    if(p == ""){
        return p;
    }
    
    if(isCorrect(p)){
        return p;
    }
    
    for(int i = 0; i < p.length(); ++i){
        s1 += p[i];
        
        if(i == 0){
            s.push(p[i]);
        }else if(s.top() == ')' && p[i] == '('){
            s.pop();
        }else if(s.top() == '(' && p[i] == ')'){
            s.pop();
        }else{
            s.push(p[i]);
        }
        
        if(s.empty()){
            for (int j = i + 1; j < p.length(); ++j) {
                s2 += p[j];
            }

            if(isCorrect(s1)){
                return s1 + getBalanceStr(s2);
            }else{
                return "(" + getBalanceStr(s2) + ")" + changeBracket(s1);
            }
        }
    }
}

string solution(string p) {
    string answer = "";
    
    if(p.empty()){
        return p;
    }
    
    string u = "";
    string v = "";
    int cnt = 0;
    
    for(int i = 0; i < p.length(); ++i){
        if(p[i] == '('){
            cnt++;
        }else{
            cnt--;
        }
        
        if(cnt == 0){
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    if(isCorrect(u)){
        answer = u + solution(v);
    }else{
        answer = "(" + solution(v) + ")";
        
        for(int i = 1; i < u.length() - 1; ++i){
            if (u[i] == '(') {
                answer += ')';
            } else {
                answer += '(';
            }
        }
    }
    
    return answer;
}