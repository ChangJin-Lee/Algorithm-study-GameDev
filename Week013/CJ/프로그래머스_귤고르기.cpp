#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> maps;
    vector<pair<int,int>> p;
    
    for(auto t : tangerine)
    {
        if(maps.find(t) == maps.end())
        {
            maps[t] = 1;
        }
        else
        {
            maps[t]++;
        }
    }
    
    for(auto element : maps)
    {
        p.push_back({element.second, element.first});
    }
    
    sort(p.begin(), p.end());
    
    int l = tangerine.size() - k;
    
    while(l > 0)
    {
        if(p[0].first <= l)
        {
            l -= p[0].first;
            p.erase(p.begin());
        }
        else
        {
            break;
        }
    }
    
    return p.size();
}