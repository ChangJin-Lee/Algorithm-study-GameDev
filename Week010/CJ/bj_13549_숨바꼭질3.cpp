#include <iostream>
#include <vector>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n,k;
    int answer = 100001;
    bool visit[100001] = {false,};
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;    // 시간, 정점

    cin >> n >> k;
    
    visit[n] = true;
    q.push({0,n});

    while(!q.empty())
    {
        pair<int,int> front = q.top();
        q.pop();

        int count = front.first;
        int currentPosition = front.second;
        int teleportPosition = currentPosition * 2;
        int walkForwardPosition = currentPosition + 1;
        int walkBackwardPosition = currentPosition - 1;

        // cout << currentPosition << " " << count << "\n";

        if(currentPosition == k)
        {
            cout << count;
            break;
        }
        
        if(teleportPosition < 100001 && !visit[teleportPosition])
        {
            q.push({count, teleportPosition});
            visit[teleportPosition] = true;
        }

        if(walkBackwardPosition >= 0  && !visit[walkBackwardPosition])
        {
            q.push({count+1, walkBackwardPosition});
            visit[walkBackwardPosition] = true;
        }

        if(walkForwardPosition < 100001  && !visit[walkForwardPosition])
        {
            q.push({count+1, walkForwardPosition});
            visit[walkForwardPosition] = true;
        }
    }

}