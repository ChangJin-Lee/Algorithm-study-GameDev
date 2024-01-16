#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int getIndex(int index, string words)
{
    return int(words[index]) - (int)'a';
}

void setVectorToZero(vector<int> &v)
{
    for(int index; index < v.size(); index++)
    {
        v[index] = 0;
    }
}

int main()
{
    fastcpp;
    int n;
    bool checkGroup;
    int answer = 0;
    string input;
    vector<int> v(26,0);

    cin >> n;
    for(int index = 0; index < n; index++)
    {
        cin >> input;
        checkGroup = true;
        setVectorToZero(v);
        v[int(input[0]) - (int)'a'] = 1;
        for(int innerIndex = 1; innerIndex < input.size(); innerIndex++)
        {
            int vIndex = getIndex(innerIndex, input);
            if (input[innerIndex] != input[innerIndex-1])
            {
                if(v[vIndex] == 1)
                {
                    checkGroup = false;
                    break;
                }
            }
            v[vIndex] = 1;
        }
        if(checkGroup)
        {
            answer++;
        }
    }
    cout << answer;
}

