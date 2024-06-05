#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<pair<int,int>> stack; // index, value
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> answerPair;
    int pairIndex = 0;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        while(!stack.empty() && stack.back().second < numbers[i])
        {
            answerPair.push({stack.back().first, numbers[i]});
            stack.pop_back();
        }
        
        stack.push_back({++pairIndex, numbers[i]});
    }
    
    for(pair<int,int> pair : stack)
    {
        answerPair.push({pair.first, -1});
    }
    stack.clear();
    
    // ## 이 부분 설명!
    // while(!stack.empty())
    // {
    //     answerPair.push({stack.front().first, -1});
    //     stack.erase(stack.begin());
    // }

    stack.erase(stack.begin());
    
    while(!answerPair.empty())
    {
        answer.push_back(answerPair.top().second);
        answerPair.pop();
    }
    
    return answer;
}