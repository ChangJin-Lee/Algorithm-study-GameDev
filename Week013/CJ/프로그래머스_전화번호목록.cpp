#include <string>
#include <vector>
#include <queue>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    priority_queue<string, vector<string>, greater<string>> pq;
    for(auto s : phone_book)
    {
        pq.push(s);
    }
    string target = pq.top();
    pq.pop();
    
    while(!pq.empty())
    {
        int slicing = target.size();
        if(target == pq.top().substr(0,slicing))
        {
            return false;
        }
        target = pq.top();
        pq.pop();
    }
    
    return answer;
}