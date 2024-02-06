#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    string input;
    char cmd;
    vector<char> left, right;

    cin >> input >> n;

    for(int i = 0; i < input.size(); i++)
    {
        left.push_back(input[i]);
    }

    while(n--)
    {
        cin >> cmd;

        if(cmd == 'P')
        {
            cin >> cmd;
            left.push_back(cmd);
        }
        else
        {
            if(cmd == 'L')
            {
                if(!left.empty())
                {
                    right.push_back(left.back());
                    left.pop_back();
                }
            }
            else if (cmd == 'D')
            {
                if(!right.empty())
                {
                    left.push_back(right.back());
                    right.pop_back();
                }
            }
            else if (cmd == 'B')
            {
                if(!left.empty())
                {
                    left.pop_back();
                }
            }
        }
    }

    for(auto k : left)
    {
        cout << k;
    }
    reverse(right.begin(), right.end());
    for(auto k : right)
    {
        cout << k;
    }
}
