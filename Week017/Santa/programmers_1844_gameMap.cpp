#include<vector>
#include<queue>
using namespace std;

class FindWay
{
    private: 
    vector<vector<bool>> visited; 
    vector<pair<int, int>> dir = {
        {-1, 0}, 
        {1, 0}, 
        {0, -1}, 
        {0, 1}
    };
    queue<pair<int,int>> myQ;
    int answer = -1;
    pair<int, int> cur = {0,0};
    pair<int, int> target; 
    pair<int, int> addPair(pair<int,int> a, pair<int,int> b)
    {
      return make_pair(a.first + b.first, a.second + b.second);  
    };
    
    public: 
    FindWay(pair<int,int> endPoint)
    {
        this->target = make_pair(endPoint.first - 1, endPoint.second - 1);
        this->visited.resize(endPoint.first, vector<bool>(endPoint.second, 0));
    };
    void BFS(vector<vector<int>>& maps);
    int getAnswer(){ return answer; };
};

void FindWay::BFS(vector<vector<int>>& maps)
{
    myQ.push(cur);
    
    while(!myQ.empty())
    {                
        pair<int, int> pos = myQ.front();
        myQ.pop();
        visited[pos.first][pos.second] = true;
        
        for(auto d : dir)
        {
            pair <int, int> temp = addPair(pos, d); 
            if(temp.first < 0 || temp.first > target.first || 
               temp.second < 0 || temp.second > target.second)
                continue;
         
            if(temp == target)
            {
                answer = maps[pos.first][pos.second] + 1;
                return;
            }
            
            if(!visited[temp.first][temp.second] && maps[temp.first][temp.second])
            {
                myQ.push(temp);
                visited[temp.first][temp.second] = true;
                maps[temp.first][temp.second] = maps[pos.first][pos.second] + 1;
            }
        }
    }
} 

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    pair<int, int> target(maps.size(), maps[0].size());
    
    FindWay finder(target);
    
    finder.BFS(maps);
    answer = finder.getAnswer();
    
    return answer;
}