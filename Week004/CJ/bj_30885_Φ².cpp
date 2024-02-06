#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int CountZero(vector<pair<int,int>> &v)
{
    int tmp = 0;
    for(auto k : v)
    {
        if(k.second == 0)
            tmp++;
    }
    return tmp;
}


int main()
{
    fastcpp;
    int n, input;
    vector<pair<int, int>> v;

    cin >> n;

    for(int i = 0; i < n; i ++)
    {
        cin >> input;
        v.push_back({i, input});
    }


    while(CountZero(v) < n-1)
    {

        // for(auto k : v)
        // {
        //     cout << k.first << "  " <<  k.second << "\n";
        // }
        // cout << "start\n";

        for(int i = 0; i < n; i++)
        {
            // cout << i << " " << n << "\n";
            // for(auto k : v)
            // {
            // cout << k.first << "  " <<  k.second << "\n";
            // }
            if(v[i].second != 0)
            {
                // 왼쪽, 오른쪽에 숫자가 있는경우
                if( 0 < i && i < n-1)
                {
                    // 2 4 3
                    if( v[i-1].second <= v[i].second && v[i].second >= v[i+1].second)
                    {
                        int val = v[i-1].second + v[i].second + v[i+1].second;
                        v[i-1].second = 0;
                        v[i].second = 0;
                        v[i+1].second = val;
                        v[i+1].first = v[i].first;
                        v[i-1].first = v[i].first;
                        i++;
                    }
                    // 2 4 5
                    else if( v[i-1].second <= v[i].second && v[i].second < v[i+1].second)
                    {
                        v[i].second += v[i-1].second;
                        v[i-1].second = 0;
                    }
                    // 5 4 2
                    else if (v[i-1].second > v[i].second && v[i].second >= v[i+1].second)
                    {
                        v[i+1].second += v[i].second;
                        v[i+1].first = v[i].first;
                        v[i].second = 0;
                        i++;
                    }
                }
                // 오른쪽에만 숫자가 있는 경우
                else if ( i == 0)
                {
                    if( v[i+1].second <= v[i].second)
                    {
                        v[i+1].second += v[i].second;
                        v[i+1].first = v[i].first;
                        v[i].second = 0;
                        i++;
                    }
                }
                // 왼쪽에만 숫자가 있는 경우
                else if ( i == n-1)
                {
                    if( v[i-1].second <= v[i].second )
                    {
                        v[i-1].second += v[i].second;
                        v[i-1].first = v[i].first;
                        v[i].second = 0;
                    }
                }
            }
        }
    }

    for(auto k : v)
    {
        if(k.second != 0)
            cout << k.second << "\n" << k.first+1 ;
        // cout << k.first << "  " <<  k.second << "\n";
    }


    // cout << v.front().second << "\n" << v.front().first + 1;
}