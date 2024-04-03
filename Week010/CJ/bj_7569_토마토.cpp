#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int m,n,h,answer;
vector<tuple<int,int,int>> startingPoint; // z, x, y
vector<vector<vector<int>>> v;
vector<vector<vector<bool>>> visit; // z, x, y
tuple<int,int,int> movable[6] = {{1,0,0},{-1,0,0},{0,-1,0}, {0,0,1}, {0,1,0}, {0,0,-1}}; // z, x, y

void bfs();

int main()
{
    fastcpp;
    int input;

    cin >> m >> n >> h;

    answer = 10000001;

    v.assign(h, vector<vector<int>>(n, vector<int>(m,0)));
    visit.assign(h, vector<vector<bool>>(n,vector<bool>(m,false)));

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                cin >> v[i][j][k];
                if(v[i][j][k] == 1)
                    startingPoint.push_back({i,j,k});
            }
        }
    }

    bfs();

    for(auto heights : v)
    {
        for(auto rows : heights)
        {
            for(auto t : rows)
            {
                if(t==0)
                    answer = -1;
            }
        }
    }

    cout << answer;
}

void bfs()
{
    queue<tuple<int,int,int,int>> q; // z, x, y, level
    
    for(auto k : startingPoint)
    {
        q.push({get<0>(k),get<1>(k),get<2>(k),0});
        visit[get<0>(k)][get<1>(k)][get<2>(k)] = true;
    }
        
    while(!q.empty())
    {
        tuple<int,int,int,int> front = q.front();
        q.pop();

        answer = get<3>(front);

        for(auto k : movable)
        {
            int nextZ = get<0>(k) + get<0>(front);
            int nextX = get<1>(k) + get<1>(front);
            int nextY = get<2>(k) + get<2>(front);
            int nextLevel = 1 + get<3>(front);

            if( 0 <= nextZ && nextZ < h && 0 <= nextX && nextX < n && 0 <= nextY && nextY < m)
            {
                if(v[nextZ][nextX][nextY] != -1 && !visit[nextZ][nextX][nextY])
                {
                    if(v[nextZ][nextX][nextY] == 0)
                    {
                        v[nextZ][nextX][nextY] = 1;
                    }
                    q.push({nextZ,nextX,nextY,nextLevel});
                    visit[nextZ][nextX][nextY] = true;
                }
            }
        }
    }
}