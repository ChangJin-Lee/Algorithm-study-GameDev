#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, input;
    vector<pair<int,int>> a, p;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back({input, i});
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++)
    {
        p.push_back({a[i].second, i});
    }

    sort(p.begin(), p.end());

    for(int i = 0; i < n; i++)
    {
        cout << p[i].second << " ";
    }
}