#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastcpp;

    queue<int> tq;
    queue<pair<int, int> > bridge;
    int cur_weight = 0; // 현재 다리에 올라가있는 트럭의 무게의 합
    int time = 0;
    int n; // 트럭의 수
    int w; // 다리의 길이
    int l; // 최대 하중
    cin >> n >> w >> l;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tq.push(t);
    }

    while (!tq.empty() || !bridge.empty())
    {
        if (!bridge.empty() && ((bridge.front().first + w) == time))
        {
            cur_weight -= bridge.front().second;
            bridge.pop();
        }
        // 현재 다리에 있는 트럭의 무게 + 큐 가장 앞의 트럭의 무게가 최대 하중보다 작으면
        if (!tq.empty() && ((cur_weight + tq.front()) <= l) && (bridge.size() < w))
        {
            bridge.push(make_pair(time, tq.front()));
            cur_weight += tq.front();
            tq.pop();
        }

        time++;
    }

    cout << time;

    return 0;
}