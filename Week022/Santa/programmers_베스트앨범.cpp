#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 많이 재생한 장르
    // 장르 중 많이 재생한 곡
    // 같은 시 인덱스가 작은거 먼저
    // key = 장르, value = {장르 총 재생 횟수, 노래 재생 횟수, 노래 인덱스}

    // key: genres / value: 총 재생 횟수
    map<string, int> m1; 
    // key: genres / value: 재생 횟수, idx 
    map<string, vector<pair<int, int>>> m2; 
    
    for(int idx = 0; idx < genres.size(); ++idx)
    {
        m1[genres[idx]] += plays[idx];
        m2[genres[idx]].push_back({plays[idx], idx});
    }
    
    // 노래를 재생 횟수 내림차순, 인덱스 오름차순으로 정렬 
    for(auto &v : m2)
    {
        sort(v.second.begin(), v.second.end(), [](const pair<int, int> &a, const pair<int ,int> &b){
            if(a.first == b.first)
            {
                return  a.second < b.second;
            }

            return a.first > b.first;
        });
    }
    
    // 총 재생 횟수 많은 순으로 장르 정렬
    vector<pair<string, int>> mylist(m1.begin(), m1.end());
    sort(mylist.begin(), mylist.end(), [](const pair<string, int> &a, const pair<string, int> &b){
        return a.second > b.second;
    });
    
    for(pair<string, int> g : mylist)
    {
        for(int i = 0; i < 2; ++i)
        {
            answer.push_back(m2[g.first][i].second);
         
            if(m2[g.first].size() < 2)
            {
                break;
            }   
        }
    }
    
    return answer;
}

