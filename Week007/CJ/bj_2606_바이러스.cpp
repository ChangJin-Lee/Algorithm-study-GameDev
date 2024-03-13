#include <iostream>
#include <vector>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, m, u, v;
    int answer = 0;
    vector<vector<int>> computers;
    vector<bool> visited;
    queue<int> q;

    cin >> n >> m;

    computers.assign(n+1,vector<int>());
    visited.assign(n+1, false);

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        computers[u].push_back(v);
        computers[v].push_back(u);
    }

    q.push(1);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto computer : computers[front])
        {
            if(!visited[computer])
            {
                visited[computer] = true;
                q.push(computer);
                answer++;
            }
        }
    }

    if(answer == 0)
        cout << answer;
    else
        cout << answer-1;
}