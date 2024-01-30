#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastcpp;

    // pair<height, index>
    stack<pair<int, int> > s;
    pair<int, int> p;
    int n;
    cin >> n;
    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        while (!s.empty())
        {
            if (cur < s.top().first)
            {
                cout << s.top().second << " ";
                break;
            }
            s.pop();
        }
        if (s.empty())
        {
            cout << 0 << " ";
        }
        s.push(make_pair(cur, i+1));
    }

    return 0;
}