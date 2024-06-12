#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

class islands
{
    public: 
    virtual vector<int> durationOfStay() = 0;

    vector<vector<int>> maps;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int maxY = 0;
    int maxX = 0;
    
    vector<int> answer; 
    
    islands(vector<string>& i_maps)
    {
        this->maxY = i_maps.size();
        this->maxX = i_maps[0].length();

        maps.assign(maxY, vector<int>(maxX, 0));

        for(int y = 0; y < maxY; ++y)
        {
            for(int x = 0; x < maxX; ++x)
            {
                if(i_maps[y][x] == 'X')
                {
                    maps[y][x] = 0;
                }
                else
                {
                    maps[y][x] = i_maps[y][x] - '0';
                }
            }
        }
    }
};

class investigatingIsland : public islands
{
    public:
    investigatingIsland(vector<string>& i_maps) : islands(i_maps){}

    vector<int> durationOfStay() override;

    int DFS(int y, int x);
};

vector<int> investigatingIsland::durationOfStay()
{
    for(int y = 0; y < maxY; ++y)
    {
        for(int x = 0; x < maxX; ++x)
        {
            if(maps[y][x] != 0)
            {
                int result = DFS(y,x);
                if(result != 0)
                {
                    answer.push_back(result);
                }
            }
        }
    }

    if(answer.empty())
    {
        answer.push_back(-1);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int investigatingIsland::DFS(int y, int x)
{
    if(y < 0 || y >= maxY || x < 0 || x >= maxX || maps[y][x] == 0)
    {
        return 0;
    }

    int value = maps[y][x]; 
    maps[y][x] = 0;

    for(auto& p : dir)
    {
        value += DFS(y + p.first, x + p.second);
    }

    return value;
}


vector<int> solution(vector<string> maps) 
{
    investigatingIsland myIsland(maps);
    
    return myIsland.durationOfStay();
}