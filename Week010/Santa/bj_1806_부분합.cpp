#include <iostream>
#include <limits.h> 
#include <algorithm>
#include <vector> 

using namespace std; 

vector<int> inputs;

#define MaxNum INT32_MAX

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n, k, ans = MaxNum;

    cin >> n >> k;

    inputs.assign(n, 0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >>  inputs[idx];
    }

    int st = 0, en = 0;
    long long sum = inputs[0];

    while(st <= n && en <= n)
    {
        // 합이 k보다 작으면 오른쪽으로 이동
        if(sum < k)
        {
            en++;
            sum += inputs[en];
            if(en == n) break;
        }
        // 합이 k보다 크면 en과 st의 거리 계산 후 st 오른쪽으로 이동
        else
        {
            sum -= inputs[st];
            ans = min(ans, en - st + 1);
            st++;
        }
    }

    cout << (ans == MaxNum ? 0 : ans);

    return 0;
}