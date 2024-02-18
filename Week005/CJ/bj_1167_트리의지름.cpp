#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

vector<pair<int,int>> v[100001]; // first : 연결 정점, second : 거리
vector<bool> visit;
int maxEdge = 0;
int maxVertex = 1;

void dfs(int k, int p);

int main()
{
    fastcpp;
    int n,input, vertex, edge;
    int answer = 0;

    cin >> n;
    visit.assign(n+1, false);
    
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        
        while(cin >> vertex)
        {
            if(vertex == -1) break;
            cin >> edge;
            v[input].push_back({vertex, edge});
        }
    }

    
    dfs(1, 0);
    for(int i = 0; i < n+1; i++)
    {
        visit[i] = false;
    }
    dfs(maxVertex,0);
    cout << maxEdge;
}

void dfs(int k, int p)
{
    bool chk = false;
    visit[k] = true;

    for(auto j : v[k])
    {
        if(!visit[j.first])
        {
            dfs(j.first, p + j.second);
            chk = true;
        }
    }

    if(!chk)
    {
        if(maxEdge < p)
        {
            maxEdge = p;
            maxVertex = k;
        }
    }
    
}