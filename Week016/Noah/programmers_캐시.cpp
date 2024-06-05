#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int LRU(list<string> &cache, string city, int cacheSize){
    // 캐시에 없을때
    if(find(cache.begin(), cache.end(), city) == cache.end()){
        // 캐시가 다 찬 경우
        if(cache.size() == cacheSize){
            cache.pop_back();
        }
        cache.push_front(city);
        return 5;
    }else{
        cache.erase(find(cache.begin(), cache.end(), city));
        cache.push_front(city);
        return 1;
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    
    // list의 back에 가까워질수록 오래 사용 안한거
    list<string> cache(cacheSize);
    
    for(int i = 0; i < cities.size(); ++i){
        for(int j = 0; j < cities[i].length(); ++j){
            if(cities[i][j] >= 'A' && cities[i][j] <= 'Z'){
                cities[i][j] += 32;
            }
        }
    }
    
    for(int i = 0; i < cities.size(); ++i){
        answer += LRU(cache, cities[i], cacheSize);
    }
    
    return answer;
}