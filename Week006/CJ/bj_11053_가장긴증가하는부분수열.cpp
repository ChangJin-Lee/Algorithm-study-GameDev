#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, input;
    int answer = 0;
    vector<int> dp;

    cin >> n;

    cin >> input;
    dp.push_back(input);

    for(int i = 1; i < n; i++)
    {
        int target = 0;
        bool check = false;
        cin >> input;
        
        for(int j = 0; j < dp.size(); j++)
        {
            if(input <= dp[j])
            {
                check = true;
                target = j;
                break;
            }
        }
        if(!check)
            dp.push_back(input);
        else
            dp[target] = input;
            
    }

    cout << dp.size();
}