#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

// 반례 모음집
// https://www.acmicpc.net/board/view/31853

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string n;
vector<int> button;
vector<int> brokenButton;

int bfs();

int main()
{
    fastcpp;
    
    int m, answer;
    
    cin >> n >> m;

    brokenButton.assign(m,0);

    for(int i = 0; i < m; i++)
    {
        cin >> brokenButton[i];
    }

    for(int i = 0; i <= 9; i++)
    {
        bool check = false;
        for(int j = 0; j < m; j++)
        {
           if(i == brokenButton[j])
           {
                check = true;
           }
        }
        if(!check)
        {
            button.push_back(i);
        }
    }

    if(abs(stoi(n)-100) <= n.size())
            cout << abs(stoi(n)-100);
    else
    {
        cout << min(bfs(),abs(stoi(n) - 100));
    }
}

int bfs()
{
    // 채널, 레벨
    queue<pair<string, int>> q;
    int answer = 500001;
    int nearestLeftTarget = -10;
    int nearestRightTarget = 10;
    int FarLeftTarget = 1;
    int FarRightTarget = -1;
    int idx1, idx2, idx3, idx4;


    for(auto b : button)
    {
        int diff = int(n[n.size()-1] - '0') - b;

        if(diff < 0)
        {
            if(nearestLeftTarget < diff)
            {
                nearestLeftTarget = diff;
                idx1 = b;
            }
            if(FarLeftTarget > diff)
            {
                FarLeftTarget = diff;
                idx3 = b;
            }
        }
        else
        {
            if(nearestRightTarget > diff)
            {
                nearestRightTarget = diff;
                idx2 = b;
            }
            if(FarRightTarget < diff)
            {
                FarRightTarget = diff;
                idx4 = b;
            }
        }
    }

    if(nearestLeftTarget != -10)
        q.push({to_string(idx1), 1});
    if(nearestRightTarget != 10)
        q.push({to_string(idx2), 1});
    if(FarLeftTarget != 1 && FarLeftTarget != nearestLeftTarget)
        q.push({to_string(idx3), 1});
    if(FarRightTarget != -1 && FarRightTarget != nearestRightTarget)
        q.push({to_string(idx4), 1});

    while(!q.empty())
    {
        int nearestLeftTarget = -10;
        int nearestRightTarget = 10;
        int FarLeftTarget = 1;
        int FarRightTarget = -1;
        int idx1, idx2, idx3;
        string curStr = q.front().first;
        int level = q.front().second;
        q.pop();

        if(n.size() - 1 <= level && level <= n.size() + 1)
        {
            int cur = 0;
            while(curStr[cur] == '0')
            {
                if(cur < curStr.size()-1)
                    cur++;
                if(cur >= curStr.size()-1)
                    break;
            }
            answer = min(answer, abs(stoi(n) - stoi(curStr)) + level - cur);
        }
        
        if(level == n.size())
        {
            for(auto b : button)
            {
                q.push({to_string(b) + curStr, level+1});
            }
        }
        else if(level < n.size())
        {
            for(auto b : button)
            {
                int diff = int(n[n.size() - level - 1 ] - '0') - b;

                if(diff < 0)
                {
                    if(nearestLeftTarget < diff)
                    {
                        nearestLeftTarget = diff;
                        idx1 = b;
                    }
                     if(FarLeftTarget > diff)
                    {
                        FarLeftTarget = diff;
                        idx3 = b;
                    }
                }
                else if (diff > 0)
                {
                    if(nearestRightTarget > diff)
                    {
                        nearestRightTarget = diff;
                        idx2 = b;
                    }
                    if(FarRightTarget < diff)
                    {
                        FarRightTarget = diff;
                        idx4 = b;
                    }
                }
                else
                {
                    q.push({to_string(b) + curStr, level+1});
                }
            }
        }
        
        if(nearestLeftTarget != -10)
            q.push({to_string(idx1) + curStr, level+1});
        if(nearestRightTarget != 10)
            q.push({to_string(idx2) + curStr, level+1});
        if(FarLeftTarget != 1 && FarLeftTarget != nearestLeftTarget)
            q.push({to_string(idx3) + curStr, level+1});
        if(FarRightTarget != -1 && FarRightTarget != nearestRightTarget)
            q.push({to_string(idx4) + curStr, level+1});
    }

    return answer;
}