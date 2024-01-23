#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<string> v;

    string s;
    string sorted_s;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        v.push_back(s.substr(i, s.size()));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < s.size(); i++){
        cout << v[i] << "\n";
    }

    sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    return 0;
}