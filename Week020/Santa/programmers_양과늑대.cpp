#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
int answer = 0;

void DFS(vector<int>& info, int cur, int sheep, int wolf, queue<int> q)
{
    if(info[cur] == 0)
    {
        sheep++;
    }
    else
    {
        wolf++;
    }
    
    // 방문한 노드에서 양이 늑대보다 같거나 작아지면 탈출 <- 다른 노드로 가서 양을 모아오라
    if(sheep <= wolf) return;
    answer = max(answer, sheep);
    
    for(int idx = 0; idx < tree[cur].size(); ++idx)
    {
        // 자식을 q에 담음
        q.push(tree[cur][idx]);
    }
    
    // q의 노드를 하나씩 방문
    for(int idx = 0; idx < q.size(); ++idx)
    {
        int next = q.front();
        q.pop();
        DFS(info, next, sheep, wolf, q);
        q.push(next);
    }    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    tree.resize(info.size());
    
    for (vector<int> edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
    }
    
    queue<int> q;
    
    DFS(info, 0, 0, 0, q);
    return answer;
}