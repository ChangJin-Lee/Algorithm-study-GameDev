#include <iostream> 
#include <vector> 

using namespace std; 

class findWay
{
    private: 
    vector<vector<int>> map;
    vector<vector<int>> puddles;
    int m, n;

    public:
    findWay(int m, int n, vector<vector<int>> puddles)
    {
        this->m = m;
        this->n = n;
        map.assign(n, vector<int>(m, 0));
        this->puddles = puddles;
        for(auto& vec : puddles)
        {
            map[vec[1]-1][vec[0]-1] = -1;
        }
    }

    int findShortestWays();
};

int findWay::findShortestWays()
{    
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < m; ++x)
        {
            // 웅덩이
            if(map[y][x] == -1)
            {
                map[y][x] = 0;
            }
            else if( y == 0 && x == 0)
            {
                map[y][x] = 1;
            }
            // 첫 행
            else if(y == 0)
            {
                map[y][x] = map[y][x-1];
            }
            // 첫 열
            else if(x == 0)
            {
                map[y][x] = map[y-1][x];
            }
            else
            {
                map[y][x] = (map[y-1][x] + map[y][x-1]) % 1000000007;
            }
        }
    }

    return map[n-1][m-1];
}


int solution(int m, int n, vector<vector<int>> puddles) {
    findWay myWay(m, n, puddles);
    return myWay.findShortestWays();
}