#include <iostream>

int dp[1001];

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    int n;
    cin >> n;

    // 초기값
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= n; i++){
        // int의 범위를 넘어가서 10007로 나눈 값으로 저장
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}