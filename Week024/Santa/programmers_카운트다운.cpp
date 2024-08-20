#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> dp (100001, {0,0});


void compareScore(int idx)
{
    if(dp[idx - 50].first < dp[idx - 60].first)
    {
        dp[idx] = {dp[idx - 50].first + 1, dp[idx - 50].second + 1};       
    }
    else if(dp[idx - 50].first > dp[idx - 60].first)
    {
        dp[idx] = {dp[idx - 60].first + 1, dp[idx - 60].second}; 
    }
    else
    {
        dp[idx].first = dp[idx - 50].first + 1;    
        dp[idx].second = max(dp[idx - 60].second, dp[idx - 50].second + 1);
    }
}

vector<int> solution(int target) {
    vector<int> answer;

    for(int idx = 1; idx <= target; ++idx)
    {
        // 20이하 싱글, 불
        if(idx <= 20 || idx == 50)
        {
            dp[idx] = {1, 1};
        }
        // 60이하 트리플
        else if(idx <= 60 && idx % 3 == 0)
        {
            dp[idx] = {1, 0};
        }
        // 40이하 더블 
        else if(idx <= 40 && idx % 2 == 0)
        {
            dp[idx] = {1, 0};
        }        
        // 50 초과, 70이하 
        else if(idx > 50 && idx <=70 )
        {
            dp[idx] = {2, 2};
        }
        // 70미만 불 + 싱글
        else if(idx < 70)
        {
            if(idx < 40)
            {
                dp[idx] = {2, 2};
            }
            else
            {
                dp[idx] = {2, 1};
            }
        }
        // 71이상 트리플 vs 불 비교
        else
        {
            compareScore(idx);
        }
    }
        
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    
    return answer;
}