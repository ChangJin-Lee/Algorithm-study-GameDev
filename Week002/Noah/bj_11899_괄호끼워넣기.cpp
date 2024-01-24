#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    stack<char> ch;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            if(ch.empty()){
                ch.push(s[i]);
                continue;
            }else{
                if(ch.top() == '('){
                    ch.pop();
                }else{
                    ch.push(s[i]);
                }
            }
        }else{
            ch.push(s[i]);
        }
    }

    cout << ch.size();

    return 0;
}