#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Search
{
    private:
        int maxLevel = 0;
        vector<vector<int>> graphs;
        vector<int> distance;
        vector<bool> visit;
    public:
        Search(int n, vector<vector<int>> &edges);
        int bfs(int start);
        int MaxDistance();
};

int Search::bfs(int start)
{
    queue<pair<int,int>> q; // 거리, 현재정점
    
    q.push({0,start});
    visit[start] = true;
    
    while(!q.empty())
    {
        int level = q.front().first;
        int point = q.front().second;
        q.pop();
        
        if(maxLevel < level)
        {
            maxLevel = level;
        }
        
        for(auto next : graphs[point])
        {
            if(!visit[next])
            {
                visit[next] = true;
                distance[next] = level+1;
                q.push({level+1, next});
            }
        }
    }
    return count(distance.begin(),distance.end(), maxLevel);;
}

Search::Search(int n, vector<vector<int>> &edges)
{
    distance.assign(n,0);
    graphs.assign(n,vector<int>());
    visit.assign(n,false);
    for(auto edge : edges)
    {
        graphs[edge[0]-1].push_back(edge[1]-1);
        graphs[edge[1]-1].push_back(edge[0]-1);
    }
}

int solution(int n, vector<vector<int>> edge) {
    Search search(n,edge);
    return search.bfs(0);
}

int main()
{
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}