#include<queue>
#include<vector>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    pair<int, int> target = {maps.size() - 1, maps[0].size() - 1};
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false)); 
    vector<pair<int, int>> dir = {
        {-1, 0}, 
        {1, 0}, 
        {0, -1}, 
        {0, 1}
    };
    queue<pair<int,int>> myQ;
    
    myQ.push({0, 0});
    
    while(!myQ.empty())
    {                
        pair<int, int> pos = myQ.front();
        myQ.pop();
        
        for(pair<int,int> d : dir)
        {
            pair <int, int> temp = {pos.first + d.first, pos.second + d.second}; 
            
            if(temp.first < 0 || temp.first > target.first || 
               temp.second < 0 || temp.second > target.second)
                continue;
            
            if(!visited[temp.first][temp.second] && maps[temp.first][temp.second])
            {
                if(temp == target)
                {
                    return maps[pos.first][pos.second] + 1;
                }

                myQ.push(temp);
                visited[temp.first][temp.second] = true;
                maps[temp.first][temp.second] = maps[pos.first][pos.second] + 1;
            }
        }
    }
    
    return -1;
}