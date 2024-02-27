#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
int answer = 0;

int checkVertex(vector<vector<int>> &v);
void dfs(int k);

int main()
{
    int n, m, input, k;

    cin >> n >> m;

    v.assign(n,{});
    visited.assign(n,false);

    for(int i = 0; i < m; i++)
    {
        cin >> n >> input;
        v[n-1].push_back(input-1);
        v[input-1].push_back(n-1);
    }

    do
    {
        answer++;
        k = checkVertex(v);
        if(k == -1 )
            break;
        visited[k] = true;
        dfs(k);
    }while(k != -1);
    

    cout << answer-1;
}

int checkVertex(vector<vector<int>> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(!visited[i])
            return i;
    }
    return -1;
}

void dfs(int k)
{
    for(auto e : v[k])
    {
        if(!visited[e])
        {
            visited[e] = true;
            dfs(e);
        }  
    }
       
}