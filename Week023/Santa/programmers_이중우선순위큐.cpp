#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> myDeque; 
    
    for(string s : operations)
    {
        char command = s[0]; 
        int num = stoi(s.substr(2));
        
        if(!myDeque.empty() && command == 'D')
        {
            if(num < 0)
            {
                myDeque.pop_front();
            }
            else
            {
                myDeque.pop_back();
            }
        }
        
        else if(command == 'I')
        {
            myDeque.push_back(num);
        }
        
        sort(myDeque.begin(), myDeque.end());
    }
    
    if(myDeque.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(myDeque.back());
        answer.push_back(myDeque.front());
    }
    
    return answer;
}