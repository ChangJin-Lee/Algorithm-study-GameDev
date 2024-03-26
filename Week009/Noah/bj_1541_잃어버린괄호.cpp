#include <iostream>
#include <string>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    string s;
    cin >> s;

    int ans = 0;
    bool isMinus = false;
    string temp = "";

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '-' || s[i] == '+'){
            if(isMinus){
                ans -= stoi(temp);
                temp = "";
            }else{
                ans += stoi(temp);
                temp = "";
            }
        }else{
            temp += s[i];
        }

        if(s[i] == '-'){
            isMinus = true;
        }
    }

    if(isMinus){
        ans -= stoi(temp);
    }else{
        ans += stoi(temp);
    }

    cout << ans;    

    return 0;
}