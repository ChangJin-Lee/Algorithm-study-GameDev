#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<int> FindStartPosition(vector<string> &maps, char c)
{
    vector<int> StartVector;
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            if(maps[i][j] == c)
            {
                StartVector.push_back(i);
                StartVector.push_back(j);
                return StartVector;
            }
        }
    }
}

int bfs(vector<string> &maps, vector<int> &StartPositions, char c)
{
    int sx = StartPositions[0];
    int sy = StartPositions[1];
    int returnVal = -1;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));
    queue<tuple<int,int,int>> q;
    vector<vector<int>> movable = {{1,0},{0,1},{-1,0},{0,-1}};
    
    visit[sx][sy] = true;
    q.push({sx,sy,0});
    
    while(!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int cl = get<2>(q.front());
        q.pop();
        
        if(maps[cx][cy] == c)
        {
            returnVal = cl;
            break;
        }
        
        for(auto move : movable)
        {
            int nx = cx + move[0];
            int ny = cy + move[1];
            
            if((0 <= nx && nx < maps.size()) && (0 <= ny && ny < maps[0].size()))
            {
                if(!visit[nx][ny] && maps[nx][ny] != 'X')
                {
                    visit[nx][ny] = true;
                    q.push({nx,ny,cl+1});
                }
            }
        }
    }
    
    return returnVal;
}

int solution(vector<string> maps) {
    int answer = 0;
    vector<int> StartPositions;
    
    StartPositions = FindStartPosition(maps, 'S');
    answer = bfs(maps, StartPositions, 'L');
    if(answer != -1)
    {
        StartPositions = FindStartPosition(maps, 'L');
        int t = bfs(maps, StartPositions, 'E');
        if(t != -1)
        {
            answer += t;
        }
        else
        {
            return -1;
        }
    }
    
    return answer;
}