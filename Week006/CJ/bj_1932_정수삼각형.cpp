#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, input;
    vector<int> dp;
    vector<int> pastDp;

    cin >> n;

    dp.assign(n,0);

    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j <= i; j++)
        {
            cin >> input;
            v.push_back(input);
        }
        dp[0] += v[0];
        if(i != 0)
            dp[i] += pastDp[i-1] + v[i];

        for(int j = 1; j < i; j++)
        {
            dp[j] = max(pastDp[j-1] + v[j], pastDp[j] + v[j]);
        }

        pastDp = dp;
    }
    cout << *max_element(dp.begin(), dp.end());
}