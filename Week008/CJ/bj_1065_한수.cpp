#include <iostream>
#include <string>
#include <math.h>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

bool IsHanSu(string s);

int main()
{
    fastcpp;
    int n;
    int answer = 0;
    string nString;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        nString = to_string(i);
        if(IsHanSu(nString))
            answer++;
    }

    cout << answer;
}

bool IsHanSu(string s)
{
    int dif;

    if(s.size() == 1)
        return true;

    dif = s[1] - s[0];

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] - s[i-1] != dif)
            return false;
    }

    return true;
}