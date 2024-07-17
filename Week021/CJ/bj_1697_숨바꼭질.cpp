#include <iostream>
#include <queue>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n,k;
    int answer = 100001;
    bool visit[100002] = {false,};
    queue<pair<int,int>> q;

    cin >> n >> k;
    
    visit[n] = true;
    q.push({n,0});

    while(!q.empty())
    {
        pair<int,int> front = q.front();
        q.pop();

        int currentPosition = front.first;
        int teleportPosition = currentPosition * 2;
        int walkForwardPosition = currentPosition + 1;
        int walkBackwardPosition = currentPosition - 1;
        int count = front.second + 1;

        if(currentPosition == k)
        {
            if(answer > count - 1)
                answer = count - 1;
        }

        if(teleportPosition < 100001 && !visit[teleportPosition])
        {
            q.push({teleportPosition, count});
            visit[teleportPosition] = true;
        }
        if(walkForwardPosition < 100001 && !visit[walkForwardPosition])
        {
            q.push({walkForwardPosition, count});
            visit[walkForwardPosition] = true;
        }
        if(walkBackwardPosition > 0 && !visit[walkBackwardPosition])
        {
            q.push({walkBackwardPosition, count});
            visit[walkBackwardPosition] = true;
        }
            
    }

    cout << answer;
}