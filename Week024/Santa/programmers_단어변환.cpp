#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isConvertible(string begin, string target)
{
    int diff = 0;
    for(int i = 0; i < begin.length(); ++i)
    {
        if(begin[i] != target[i])
        {
            diff += 1;
            
            if(diff > 1)
            {
                return false;
            }
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<bool> isVisited(words.size());
    
    // 변환 가능한 문자, 변환 횟수
    queue<pair<string, int>> myQ; 
    
    // 변환 가능한 문제가 없다면 0
    if(find(words.begin(), words.end(), target) == words.end())
    {
        return answer; 
    }
    
    myQ.push({begin, 0});
    
    while(!myQ.empty())
    {
        pair<string, int> temp = myQ.front();
        myQ.pop();
        
        for(int i = 0; i < words.size(); ++i)
        {
            if(isVisited[i])
            {
                continue;
            }
            
            if(isConvertible(temp.first, words[i]))
            {
                if(words[i] == target)
                {
                    return temp.second + 1;
                }
                
                myQ.push({words[i], temp.second + 1});
            }
        }
    }
    
    return answer;
}