#include<iostream>
#include<vector> 
#include<queue>

using namespace std; 

int main()
{
    int n, answer = 0;
    int curTime = 0;

    cin >> n; 
    
    int dp[10001] = {0};              // 누적 실행 작업 시간 
    int time [10001] = {0};           // 작업 시간 
    int precedingCount[10001] = {0};  // 선행 작업 갯수
    vector<int> jobs [10001];   // [작업]에 대한 선행 작업의 리스트
    queue<int> waitingList;     // 대기 작업

    // 작업을 입력 받음
    // 선행 작업이 있다면 선행 작업의 인덱스에 해당 작업 푸쉬백
    // 선행 작업이 없다면 큐에 넣기 (작업 순서, 실행 시간)
    // 큐에 넣은 작업을 하나씩 꺼냄
    // 큐에서 뺀 작업이 선행 작업인 작업들을 꺼내서 계산
    // 현재 작업 시간과 이전 작업 + 지금 작업 시간 비교
    // 마지막 작업의 시간이 총 실행 시간

    for(int i = 1; i <= n; ++i)
    {
        int count; 

        cin >> time[i] >> count; 

        dp[i] = time[i];
        precedingCount[i] = count;

        // 선행 작업이 없는 작업을 큐에 넣음
        if(count == 0)
        {
            waitingList.push({i});      
            continue;
        }

        // 해당 선행 작업에 현 작업을 푸쉬백
        for(int j = 0; j < count; ++j)
        {
            int pre; 
            cin >> pre;
            jobs[pre].push_back(i);
        }
    }

    while(!waitingList.empty())
    {
        int cur = waitingList.front();
        waitingList.pop();
        
        // 현재 작업을 선행작업으로 하는 작업들의 실행 시간 계산
        for(int i = 0; i < jobs[cur].size(); ++i)
        {
            // next = 후속 작업의 인덱스
            int next = jobs[cur][i];

            // 후속 작업 시간 = 누적된 후속 작업 시간 vs 현재 작업 시간 + 후속 작업 시간
            dp[next] = max(dp[next], dp[cur] + time[next]);

            // 후속 작업의 선행 작업 갯수 빼기
            precedingCount[next] -= 1;

            // 선행 작업이 없을 경우 
            if(precedingCount[next] == 0)
            {
                waitingList.push(next);
            }
        }
    }

    for(int h : dp)
    {
        answer = answer < h ? h : answer;
    }

    cout << answer;

    return 0;
}


// 훨씬 짧은 코드
/*int main()
{
    int n, answer = 0;
    cin >> n;     

    int dp[n + 1] = {0};     
    
    for(int i = 1; i <= n; ++i)
    {
        int cur, count, maxValue = 0;
        cin >> cur >> count;

        for(int j = 0; j < count; ++j)
        {
            int preP;
            cin >> preP; 
            maxValue = maxValue > dp[preP] ? maxValue : dp[preP];
        }
        dp[i] = maxValue + cur;
        answer = answer > dp[i] ? answer : dp[i];
    }
    cout << answer;
    return 0;
}
*/