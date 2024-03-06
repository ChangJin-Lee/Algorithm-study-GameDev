#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int n;
    int answer = -1001;
    vector<int> v;
    vector<int> dp;

    cin >> n;

    v.assign(n,0);
    dp.assign(n,0);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0] = v[0];
    answer = v[0];

    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1] + v[i], v[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer;
}

