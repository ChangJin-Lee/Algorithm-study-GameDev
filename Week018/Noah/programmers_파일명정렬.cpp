#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string, int, int>> v;
    
    for(int i = 0; i < files.size(); ++i){
        string str = files[i];
        string head = "";
        string num = "";
        
        int j, k;
        for(j = 0; j < str.length() && !isdigit(str[j]); ++j){
            head += str[j];
        }
        
        for(k = j; k < str.length() && (k < j + 5) && isdigit(str[k]); ++k){
            num += str[k];
        }
        
        for(auto& c : head){
            if(islower(c)){
                c -= 32;
            }
        }

        v.push_back({head, (num == "" ? 0 : stoi(num)), i});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); ++i){
        answer.push_back(files[get<2>(v[i])]);
    }
    
    return answer;
}