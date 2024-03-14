#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int m,n,answer;
vector<pair<int,int>> startingPoint;
vector<vector<int>> v;
vector<vector<bool>> visit;
pair<int,int> movable[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void bfs();

int main()
{
    fastcpp;
    int input;

    cin >> m >> n;

    answer = -1;

    v.assign(n,vector<int>(m,0));
    visit.assign(n,vector<bool>(m,false));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> input;
            v[i][j] = input;
            if(input == 1)
                startingPoint.push_back({i,j});
        }
    }

    bfs();

    for(auto rows : v)
    {
        for(auto t : rows)
        {
            if(t==0)
                answer = -1;
        }
    }


    cout << answer;

}

void bfs()
{
    queue<tuple<int,int,int>> q;
    
    for(auto k : startingPoint)
    {
        q.push({k.first,k.second,0});
        visit[k.first][k.second] = true;
    }
        
    while(!q.empty())
    {
        tuple<int,int,int> front = q.front();
        q.pop();

        if(get<2>(front) > answer)
            answer = get<2>(front);

        for(auto k : movable)
        {
            int nextX = k.first + get<0>(front);
            int nextY = k.second + get<1>(front);
            int nextLevel = 1 + get<2>(front);

            if( 0 <= nextX && nextX < n && 0 <= nextY && nextY < m)
            {
                if(v[nextX][nextY] != -1 && !visit[nextX][nextY])
                {
                    if(v[nextX][nextY] == 0)
                    {
                        v[nextX][nextY] = 1;
                    }
                    q.push({nextX,nextY,nextLevel});
                    visit[nextX][nextY] = true;
                }
            }
        }
    }
}