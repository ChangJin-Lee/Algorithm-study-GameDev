#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int n;
vector<vector<bool>> visited;
int answerNormal = 0;
int answerABNormal = 0;
int px = 0;
int py = 0;

bool checkVisited();
void bfs(int sx, int sy, vector<string> &map);
void clearVisited();

int main()
{
    fastcpp;
    vector<string> map;
    vector<string> mapAbnormal;

    cin >> n;

    map.assign(n, " ");
    mapAbnormal.assign(n, " ");
    visited.assign(n+1, vector<bool>(n+1, false));

    for(int i = 0; i < n; i++)
    {
        cin >> map[i];
        mapAbnormal[i] = map[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mapAbnormal[i][j] == 'G')
                mapAbnormal[i][j] = 'R';
        }
    }

    while(!checkVisited())
    {
        if(px == -1)
            break;
        answerNormal++;
        bfs(px,py,map);
    }

    clearVisited();

    while(!checkVisited())
    {
        if(px == -1)
            break;
        answerABNormal++;
        bfs(px,py,mapAbnormal);
    }

    cout << answerNormal << " " << answerABNormal;
}

void clearVisited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}

bool checkVisited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                px = i;
                py = j;
                return false;
            }
        }
    }

    px = -1;
    py = -1;
    return true;
}

void bfs(int sx, int sy, vector<string> &map)
{
    queue<pair<int,int>> q;
    int movable[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    visited[sx][sy] = true;
    q.push({sx,sy});

    while(!q.empty())
    {
        pair<int,int> front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();

        for(auto nextMove : movable)
        {
            int nx = x + nextMove[0];
            int ny = y + nextMove[1];

            if( 0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if(!visited[nx][ny] && map[x][y] == map[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}