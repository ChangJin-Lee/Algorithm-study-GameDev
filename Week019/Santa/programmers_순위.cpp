#include <string>
#include <cstring>
#include <vector>
#include <map> 

using namespace std;

// win, lose
map<int, pair<int, int>> myMap;
vector<vector<int>> myGraph;
bool visited[101];

void DFS(int start, int child)
{
    visited[child] = true;

    if(start != child)
    {
        myMap[start].first++;
        myMap[child].second++;
    }

    for(int idx = 0; idx < myGraph[child].size(); ++idx)
    {
        int grandChild = myGraph[child][idx];
        if(visited[grandChild]) continue;

        DFS(start, grandChild);
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    myGraph.resize(n + 1);
   
    // 0 == winner, 1 == loser
    for(vector<int> result : results)
    {
        myGraph[result[0]].push_back(result[1]);
    }

    for(int i = 1; i <= n; ++i)
    {
        DFS(i, i);
        memset(visited, false, sizeof(visited));
    }
    
    for(pair<const int, std::pair<int, int>> p : myMap)
    {
        int winCnt = p.second.first; 
        int loseCnt = p.second.second;

        if(n - 1 == winCnt + loseCnt)
        {
            answer++;
        }
    }
    return answer;
}
