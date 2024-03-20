#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s = "";
string t = "";
int convertable = 0;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void dfs(string s, string t);

int main(){
    fastcpp;
    cin >> s >> t;

    dfs(s, t);

    cout << 0;

    return 0;
}

void dfs(string s, string t){
    if(s == t){
        cout << 1;
        exit(0);
    }
    if(s.size() > t.size()){
        return;
    }
    if(t[t.length() - 1] == 'A'){
        string temp;
        temp = t.substr(0, t.length() - 1);
        dfs(s, temp);
    }
    if(t[0] == 'B'){
        string temp;
        temp = t.substr(1, t.length());
        reverse(temp.begin(), temp.end());
        dfs(s, temp);
    }
}