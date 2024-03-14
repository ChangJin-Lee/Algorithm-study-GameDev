#include <algorithm>
#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    int n,answer,end;
    vector<pair<int,int>> v;
    fastcpp;
    cin >> n;

    v.assign(n,make_pair(0,0));
    answer = 1;
    

    for(int i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());
    end = v[0].first;

    for(int i = 1; i < n; i++)
    {
        if(end <= v[i].second)
        {
            end = v[i].first;
            answer++;
        }
    }
    
    
    cout << answer;
}