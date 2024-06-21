#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std; 

// 이차원 DP 
long long dp [101][100001] = {0,};

int main()
{
    int n, k, maxValue = 0; 

    cin >> n >> k;

    // i == 아이템의 순서
    for(int i = 1; i <= n; ++i)
    {
        int weight, value;
        cin >> weight >> value;

        // 가방의 무게, 1kg부터 증가하며 넣을 수 있는 아이템 확인
        for(int j = 1; j <= k; ++j)
        {
            // 현재 가방에 넣을 수 있다면
            if(weight <= j)
            {
                // 현재 보고 있는 아이템과 현재 아이템을 넣고 남은 무게에서 넣을 수 있는 아이템의 가치의 합을
                // 지금까지 가지고 있던 가치와 비교
                dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
            }
            else
            {
                // 가방에 넣을 수 없다면 현재 가치를 유지
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k];
}