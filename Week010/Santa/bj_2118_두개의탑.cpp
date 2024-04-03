#include <iostream>
#include <vector>

using namespace std; 

vector<int> towers;
vector<int> pSum;

int main()
{
    int n, ans = 0;

    cin >> n;

    towers.assign(n + 1, 0);
    pSum.assign(n + 1, 0);

    for(int idx = 1; idx <= n; idx++)
    {
        int num;
        cin >> num;

        towers[idx] = num;
        pSum[idx] = pSum[idx - 1] + num;
    }

    for(int st = 1; st < n; st++)
    {
        for(int en = st; en <= n; en++)
        {
            // 시계 방향과 반시계 반향의 거리 비교
            int minDis = min(pSum[en] - pSum[st], pSum[n] - pSum[en] + pSum[st]);
            ans = max(ans, minDis);
        }
    }

    cout << ans;

    return 0;
}