#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    m[words[0]]++;
    
    for(int i = 1; i < words.size(); ++i){
        if(m[words[i]] != 0 || words[i].front() != words[i - 1].back()){
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        m[words[i]]++;
    }
    
    return {0, 0};
}