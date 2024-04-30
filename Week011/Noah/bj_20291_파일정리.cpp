#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n;
    cin >> n;

    // 확장자, 개수
    vector<pair<string, int> > v;
    vector<string> inputString;

    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        int dotIdx = str.find('.');
        inputString.push_back(str.substr(dotIdx+1, str.length()));
    }

    sort(inputString.begin(), inputString.end());

    string temp = inputString[0];
    int cnt = 0;

    for(int i = 0; i < n; ++i){
        if(inputString[i] == temp){
            cnt++;
        }else if(inputString[i] != temp){
            v.push_back(make_pair(temp, cnt));
            temp = inputString[i];
            cnt = 1;
        }
    }
    
    v.push_back(make_pair(temp, cnt));

    for(int i = 0; i < v.size(); ++i){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}