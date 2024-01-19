#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

bool hasComponent(vector<char> v);
char pop_front(vector<char> &v);

int main()
{
    fastcpp;
    string input = "";
    vector<vector<char>> v;
    vector<char> tmpV;

    for(int row = 0; row < 5; row++)
    {
        cin >> input;
        for(int index = 0; index < input.length(); index++)
        {
            tmpV.push_back(input[index]);
        }
        v.push_back(tmpV);
        tmpV.clear();
    }

    for(int column = 0; column < 15; column++)
    {
        for(int row = 0; row < 5; row++)
        {
            if(hasComponent(v[row]))
            {
                cout << pop_front(v[row]);
            }
        }
    }
}

// 벡터에 요소가 존재하는지 판단
bool hasComponent(vector<char> v)
{
    if(v.size() > 0)
    {
        return true;
    }
    return false;
}

// 벡터의 가장 첫번째 인덱스의 값을 POP
char pop_front(vector<char> &v)
{
    char tmp;
    tmp = v.front();
    v.erase(v.begin());
    return tmp;
}