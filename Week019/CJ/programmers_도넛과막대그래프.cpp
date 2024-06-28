#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    map<int, pair<int,int>> Graph; // in and out count
    
    for(vector<int> edge : edges)
    {
        Graph[edge[0]].second++;
        Graph[edge[1]].first++;
    }
    
    for(auto inandout : Graph)
    {
        int number =  inandout.first;
        int in = inandout.second.first;
        int out = inandout.second.second;
        
        if(out == 0)
        {
            answer[2]++;
        }
        else if ( out == 2)
        {
            if(in > 0)
            {
                answer[3]++;
            }
            else
            {
                answer[0] = number;
            }
        }
        else if ( out > 2)
        {
            answer[0] = number;
        }
    }
    
    answer[1] = Graph[answer[0]].second - answer[2] - answer[3];
    
    
    return answer;
}