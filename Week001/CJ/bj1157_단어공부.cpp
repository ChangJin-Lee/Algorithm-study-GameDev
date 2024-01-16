#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    string input;
    vector<int> v(26,0);
    int maxVal = -1;
    int chkVal = 0;
    int answer = 0;

    cin >> input;
    for (int index=0; index < input.size(); index++)
    {
        v[tolower(input[index]) - int('a')] += 1;
    }

    for (int index=0; index < v.size(); index++)
    {
        if (maxVal < v[index])
        {
            maxVal = v[index];
            answer = index;
            chkVal = 0;
        }
        else if (maxVal == v[index])
        {
            chkVal++;
        }
    }

    if (chkVal != 0)
        cout << "?";
    else
        cout << char(answer + int('A'));
}
