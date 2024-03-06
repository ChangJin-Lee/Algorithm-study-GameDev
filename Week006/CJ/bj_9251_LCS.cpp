#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    string a, b;
    vector<vector<int>> dp(1011, vector<int>(1011,0));
    int aSize, bSize;

    cin >> a >> b;

    aSize = a.size();
    bSize = b.size();

    for(int i = 1; i < aSize+1; i++)
    {
        for(int j = 1; j < bSize+1; j++)
        {
            if(a[i-1] != b[j-1])
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j-1] + 1;
        }
    }

    cout << dp[aSize][bSize];
}