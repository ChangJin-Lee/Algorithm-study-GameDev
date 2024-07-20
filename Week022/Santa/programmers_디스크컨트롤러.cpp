#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    
    // 요청 시간 오름 차순으로 정리
    sort(jobs.begin(), jobs.end());
        
    int answer = 0;
    int idx = 0;
    int currentTime = 0;
    int totalJobs = jobs.size();

    // 실행시간, 요청 시간을 오름 차순으로 정리
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waitingList; 

    while(idx < totalJobs || !waitingList.empty())
    {
        // 현재시간에 실행 할 수 있는 작업 pq에 넣기
        while(idx < totalJobs && jobs[idx][0] <= currentTime)
        {
            waitingList.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        
        // 지금 대기 작업이 있다면 짧은 실행 시간 부터 수행
        if(!waitingList.empty())
        {
            pair<int, int> temp = waitingList.top();
            waitingList.pop();
            
            // 현재시간에 실행 시간 더함
            currentTime += temp.first;
            // 현재 시간에 대기 시간을 뺀 총 작업 시간 계산
            answer += currentTime - temp.second;
        }
        else // 대기 작업이 없다면 요청 순서대로 작업
        { 
            if(idx < totalJobs)
            {
                currentTime = jobs[idx][0];
            }
        }
    }
    return answer / totalJobs;
}