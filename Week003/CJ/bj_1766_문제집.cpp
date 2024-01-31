#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    int currentProblem = 0;
    int nextProblem = 0;
    vector<int> fixed;
    vector<vector<int>> v;
    priority_queue<int> q;

    for(int index = 0; index < 32001; index++)
    {
        v.push_back({});
        fixed.push_back(0);
    }

    cin >> n >> m;
    for(int index = 0; index < m; index++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        fixed[b]++;
    }

    //  오름차순이기때문에 음의 인덱스를 넣어야한다.
    for(int index = 1; index <= n; index++)
    {
        if(fixed[index] == 0)
        {
            q.push(-index);
        }
    }

    while(!q.empty())
    {
        currentProblem = -q.top();
        q.pop();

        cout << currentProblem << " ";

        for(int index = 0; index < v[currentProblem].size(); index++)
        {
            nextProblem = v[currentProblem][index];
            fixed[nextProblem]--;

            if(fixed[nextProblem] == 0)
                q.push(-nextProblem);
        } 
    }

    cout << "\n";
}