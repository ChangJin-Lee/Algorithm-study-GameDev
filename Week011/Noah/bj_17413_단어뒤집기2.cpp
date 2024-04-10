#include <iostream>
#include <stack>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    string inputString;
    getline(cin, inputString);
    stack<char> s;

    for(int i = 0; i < inputString.length(); ++i){
        if(inputString[i] == '<'){
            if(!s.empty()){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
            }
            while(true){
                cout << inputString[i];
                if(inputString[i] == '>'){
                    break;
                }
                i++;
            }
            continue;
        }else if(inputString[i] == ' '){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << inputString[i];
        }else{
            s.push(inputString[i]);
        }
    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}