#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> map(n+1,vector<int>());
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> distance(n+1,100001);
    
    for(auto k : roads)
    {
        map[k[0]].push_back(k[1]);
        map[k[1]].push_back(k[0]);
    }
    
    distance[destination] = 0;
    pq.push({0,destination});
    
    while(!pq.empty())
    {
        int curD = pq.top().first;
        int curN = pq.top().second;
        pq.pop();
        
        for(auto k : map[curN])
        {
            if(curD + 1 < distance[k])
            {
                distance[k] = curD + 1;
                pq.push({curD+1, k});
            }
        }
    }
    
    for(auto source : sources)
    {
        if(distance[source] == 100001)
            answer.push_back(-1);
        else
            answer.push_back(distance[source]);
    }
    
    return answer;
}