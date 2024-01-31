#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastcpp;

    int num_of_paper;
    int target;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        int cnt = 0;

        cin >> num_of_paper >> target;

        for (int j = 0; j < num_of_paper; j++)
        {
            int prior;
            cin >> prior;
            q.push(make_pair(j, prior));
            pq.push(prior);
        }

        while (!q.empty())
        {
            int idx = q.front().first;
            int value = q.front().second;
            q.pop();

            if (pq.top() == value)
            {
                pq.pop();
                cnt++;
                if (target == idx)
                {
                    cout << cnt << "\n";
                    break;
                }
            }
            else
            {
                q.push(make_pair(idx, value));
            }
        }
    }

    return 0;
}