#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

vector<int> FindStartPoint(vector<string> &board)
{
    vector<int> Axis;
    
    for(int i = 0; i < board.size();i++)
    {
        for(int j = 0;j<board[0].size();j++)
        {
            if(board[i][j] == 'R')
            {
                Axis.push_back(i);
                Axis.push_back(j);
                return Axis;
            }
        }
    }
    return {0,0};
}

int bfs(vector<string> &board)
{
    queue<tuple<int,int,int>> q; // x, y, level
    vector<pair<int,int>> movable = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<int> startPoint = FindStartPoint(board);
    set<pair<int, int>> visited;
    
    q.push({startPoint[0], startPoint[1], 0});
    visited.insert({startPoint[0], startPoint[1]});
    
    while(!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int cl = get<2>(q.front());
        q.pop();
        
        for(auto move : movable)
        {
            int nx = cx;
            int ny = cy;
            int nl = cl+1;
            
            while(true)
            {
                int sx = nx + move.first;
                int sy = ny + move.second;
                if(sx < 0 || sx >= board.size() || sy < 0 || sy >= board[0].size() || board[sx][sy] == 'D')
                {
                    break;
                }
                nx = sx;
                ny = sy;
            }
            
            if(board[nx][ny] == 'G')
            {
                return nl;
            }
            
            if(visited.find({nx,ny}) == visited.end())
            {
                visited.insert({nx,ny});
                q.push({nx,ny,nl});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    return bfs(board);
}