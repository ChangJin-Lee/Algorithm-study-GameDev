#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    vector<int> dp(n+1,0), dp_prime(n+1,0);
    
    dp_prime[0] = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = (dp[i-1] + dp_prime[i-1])%10007;
        if(tops[i-1] == 1)
        {
            dp_prime[i] = (dp[i-1]*2 + dp_prime[i-1]*3)%10007;
        }
        else
        {
            dp_prime[i] = (dp[i-1] + dp_prime[i-1]*2)%10007;
        }
    }
    
    answer = (dp[n] + dp_prime[n])%10007;
    
    return answer;
}