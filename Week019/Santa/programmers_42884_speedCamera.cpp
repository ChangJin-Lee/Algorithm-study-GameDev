#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <queue>

using namespace std;

set<int> highway;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

// tuple <진입 지점, 진입 or 진출, 인덱스>

int solution(vector<vector<int>> routes) {
    int cnt = 0;
    
    for(int i = 0; i < routes.size(); ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            pq.push(make_tuple(routes[i][j], j, i));
        }
    }
    
    while(!pq.empty())
    {
        tuple<int, int, int> vehicle = pq.top();
        pq.pop();
        
        // 고속도로에 없음
        if(highway.find(get<2>(vehicle)) == highway.end())
        {
            // 진입이라면
            if(get<1>(vehicle) == 0)
            {
                highway.insert(get<2>(vehicle));
            }
        }
        // 고속도로에 있다면 전부 비우고 cnt 올림
        else
        {   
            cnt++;
            highway.clear();
        }
    }
    
    return cnt;
}