#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    fastcpp;
    int n,m,answer,l,r;
    vector<int> s;

    cin >> n >> m;

    s.assign(n+1,0);
    answer = 100000001;
    l = 0;
    r = 1;

    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for(int i = 1; i <= n; i++)
    {
        s[i] += s[i-1];
    }

    while(r <= n)
    {
        int subSum = s[r] - s[l];

        if(subSum >= m)
        {
            answer = min(answer, r-l);
            l++;
        }
        else
        {
            r++;
        }
    }

    if(answer == 100000001)
        cout << 0;
    else
        cout << answer;
}