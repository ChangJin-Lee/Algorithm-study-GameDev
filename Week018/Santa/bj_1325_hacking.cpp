#include<iostream>
#include<vector>
#include<map>

using namespace std; 

vector<vector<int>> computers(10001);
vector<bool> visited(10001);
map<int, int> counter;

int cnt;

void DFS(int cur)
{
    visited[cur] = true;
    cnt++;

    for(int next : computers[cur])
    {
        if(!visited[next])
        {
            DFS(next);
        }
    }
}

int main()
{
    int n, m, com1, com2 = 0;
    
    cin >> n >> m;

    for(int idx = 0; idx < m; ++idx)
    {
        cin >> com1 >> com2; 

        computers[com2].push_back(com1);
        counter[com2] = 0;
    }

    int max = 0;

    for(pair<int, int> com : counter)
    {
        fill(visited.begin(), visited.end(), false);
        cnt = 0;

        DFS(com.first);

        max = max < cnt ? cnt : max;

        counter[com.first] = cnt;
    }

    for(pair<int, int> com : counter)
    {
        if(counter[com.first] == max)
        {
            cout << com.first << ' ';
        }
    }

    return 0;
}