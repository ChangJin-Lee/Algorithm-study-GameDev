#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int seq = 0;
    int land_rows = land.size();
    int land_cols = land[0].size();
    vector<vector<bool>> visit(land_rows, vector<bool>(land_cols, false));
    pair<int,int> movable[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    queue<pair<int,int>> q;
    map<int,int> m;
    
    for(int i = 0; i < land_rows; i++)
    {
        for(int j = 0; j < land_cols; j++)
        {
            if(!visit[i][j] && land[i][j] > 0)
            {
                int oil_cnt = 0;
                seq++;
                land[i][j] += seq;
                visit[i][j] = true;
                q.push({i,j});
                
                while(!q.empty())
                {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    
                    for(auto move : movable)
                    {
                        int px = cx + move.first;
                        int py = cy + move.second;
                        
                        if((0 <= px && px < land_rows) && (0 <= py && py < land_cols))
                        {
                            if(!visit[px][py] && land[px][py] > 0)
                            {
                                q.push({px,py});
                                visit[px][py] = true;
                                land[px][py]+=seq;
                                oil_cnt++;
                            }
                        }
                    }
                }
                m[seq+1] = oil_cnt+1;
            }
        }
    }
    
    for(int i = 0; i < land_cols; i++)
    {
        vector<bool> passway(seq+1,false);
        int t_answer = 0;
        for(int j = 0; j < land_rows; j++)
        {
            if(land[j][i] > 0)
            {
                if(!passway[land[j][i]])
                {
                    t_answer += m[land[j][i]];
                    passway[land[j][i]] = true;
                }
            }
        }
        answer = max(answer, t_answer);
    }
    
    return answer;
}


int main()
{
    // 9
    cout << solution({{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}});

    cout << "\n";
    // 16
    cout << solution({{1, 0, 1, 0, 1, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 0}, {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}});
}