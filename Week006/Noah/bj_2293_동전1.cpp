#include <iostream>
#include <algorithm>
#include <vector>

int dp[10001];

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n, k;
    cin >> n >> k;
    // 동전 종류 넣기위한 벡터
    vector<int> v(n + 1);

    // 동전 종류 넣기
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    dp[0] = 1;

    // 동전 종류마다 k번까지 경우의 수 갱신
    for(int i = 1; i <= n; i++){
        // 동전 크기를 첫번째 크기부터 k원까지 1씩 늘리면서
        for(int j = v[i]; j <= k; j++){
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[k];

    return 0;
}