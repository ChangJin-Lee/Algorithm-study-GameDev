#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>


using namespace std;

int timeToMinutes(const string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 3600 + minutes*60;
}

int solution(vector<vector<string>> book_time) {
    int n = book_time.size();
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    set<int> rooms;
    
    for(int i = 0; i < n; ++i)
    {
        int a = timeToMinutes(book_time[i][0]);
        int b = timeToMinutes(book_time[i][1]) + 599;
        pq.push({a,i});
        pq.push({b,i});
    }
    
    while(!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();
        if(find(rooms.begin(), rooms.end(), a) == rooms.end())
        {
            rooms.insert(a);
            answer = max(answer, int(rooms.size()));
        }
        else
        {
            rooms.erase(a);
        }
    }
    
    return answer;
}