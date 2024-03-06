#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

void updateDP(vector<int> &dp, int p);

int main()
{
    fastcpp;
    int n;
    int answer = 0;
    vector<int> a(1001,0);
    vector<int> aReverse(1001,0);
    vector<int> dp;
    vector<int> dp2;

    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        aReverse[n-i+1] = a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        updateDP(dp, a[i]);

        dp2.clear();

        for(int j = 1; j <= n - i + 1; j++)
        {
            updateDP(dp2, aReverse[j]);
        }

        answer = max(answer, int(dp.size() + dp2.size()));
    }
    
    cout << answer-1;
}

void updateDP(vector<int> &dp, int p)
{
    int idx = -1;

    for(int j = 0; j < dp.size(); j++)
    {
        if(p <= dp[j])
        {
            idx = j;
            break;
        }
    }
    if(idx == -1)
    {
        dp.push_back(p);
    }
    else
    {
        dp[idx] = p;
    }
}