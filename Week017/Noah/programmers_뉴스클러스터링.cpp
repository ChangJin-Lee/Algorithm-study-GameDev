#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1;
    vector<string> s2;
    
    for(int i = 1; i < str1.length(); ++i){
        string temp = "";
        if(isalpha(str1[i - 1]) && isalpha(str1[i])){
            temp += tolower(str1[i - 1]);
            temp += tolower(str1[i]);
            s1.push_back(temp);
        }
    }
    
    for(int i = 1; i < str2.length(); ++i){
        string temp = "";
        if(isalpha(str2[i - 1]) && isalpha(str2[i])){
            temp += tolower(str2[i - 1]);
            temp += tolower(str2[i]);
            s2.push_back(temp);
        }
    }
    
    vector<string> union_vec;
    vector<string> intersection_vec;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(union_vec));
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(intersection_vec));
    
    if(union_vec.empty() && intersection_vec.empty()){
        answer = 65536;
    }else if(union_vec.empty()){
        answer = 65536;
    }else{
        answer = int(float(intersection_vec.size()) / float(union_vec.size()) * 65536.0f);
    }
    
    return answer;
}