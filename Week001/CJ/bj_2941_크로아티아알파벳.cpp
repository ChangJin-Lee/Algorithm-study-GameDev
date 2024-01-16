#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void IsCroatia(char word, int &answer, vector<char> &v)
{
    if (v.front() == word)
    {
        v.erase(v.begin());
    }
    answer++;
}

int main()
{
    fastcpp;
    vector<char> v;
    string input;
    char target;
    int answer = 0;
    cin >> input;
    for (auto k : input)
    {
        v.push_back(k);
    }

    while(v.size() > 0)
    {
        target = v.front();
        v.erase(v.begin());

        switch (target)
        {
        case 'c':
            if (v.front() == '=' || v.front() == '-')
            {
                v.erase(v.begin());
                answer ++;
            }
            else
            {
                answer++;
            }
            break;
        case 'd':
            if(v.front() == 'z')
            {
                v.erase(v.begin());
                if(v.front() == '=')
                {
                    v.erase(v.begin());
                    answer++;
                }
                else
                {
                    answer += 2;
                }
            }
            else if (v.front() == '-')
            {
                v.erase(v.begin());
                answer++;
            }
            else
            {
                answer++;
            }
            break;
        case 'l': 
        case 'n':
            IsCroatia('j', answer, v);
            break;
        case 's':
        case 'z':
            IsCroatia('=', answer, v);
            break;
        default:
            answer++;
            break;
        }
    }

    cout << answer;
}
