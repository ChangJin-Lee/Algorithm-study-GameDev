#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
 
    priority_queue<tuple<int, int, int>> pq; 
    
    int totalPicks = picks[0] + picks[1] + picks[2];
    
    for(int i = 0; i < minerals.size(); i += 5)
    {
        vector<int> mGroup = {0, 0, 0};
        
        for(int j = 0; j < 5; ++j)
        {
            if(i + j < minerals.size())
            {
                string m = minerals[i + j];
                
                if(m == "diamond")
                {
                    mGroup[0]++; 
                }
                else if(m == "iron")
                {
                    mGroup[1]++;
                }
                else if(m == "stone")
                {
                    mGroup[2]++;
                }
            }
        }
        
        pq.push(make_tuple(mGroup[0], mGroup[1], mGroup[2]));
        
        totalPicks--; 
        
        if(totalPicks == 0)
        {
            break;
        }
    }
    
    while(!pq.empty())
    {
        auto [diamond, iron, stone] = pq.top();
        pq.pop();
        
        if(picks[0] > 0)
        {
            answer += (diamond + iron + stone);
            picks[0]--;
        }
        
        else if(picks[1] > 0)
        {
            answer += (diamond * 5 + iron + stone);
            picks[1]--;
        }
        
        else if(picks[2] > 0)
        {
            answer += (diamond * 25 + iron * 5 + stone);
            picks[2]--;
        }
    }
 
    return answer;
}