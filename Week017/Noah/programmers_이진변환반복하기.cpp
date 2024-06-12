#include <string>
#include <vector>

using namespace std;

int numOfOne(string s){
    int cnt = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '1'){
            cnt++;
        }
    }
    return cnt;
}

string toBinary(int n){
    string bin;
    while(n != 0){
        bin = (n % 2 == 0 ? "0" : "1") + bin;
        n /= 2;
    }
    return bin;
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    while(true){
        int cntOne = numOfOne(s);
        answer[1] += (s.length() - cntOne);
        s = toBinary(cntOne);
        answer[0]++;
        if(s == "1"){
            break;
        }
    }
    
    return answer;
}