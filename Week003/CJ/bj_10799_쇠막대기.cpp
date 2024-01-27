#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    vector<int> v;
    string input;
    int answer = 0;

    cin >> input;

    for(int index = 0; index < input.length(); index++)
    {
        if(input[index] == '(')
        {
            v.push_back(index);
        }
        else
        {
            // index 1 차이 == 레이저
            if(v.back() == index - 1)
            {
                v.pop_back();
                answer += v.size();
            }
            // index 1 이상 차이 == 잘린 막대의 끝 부분
            else
            {
                v.pop_back();
                answer += 1;
            }
        }
    }

    cout << answer;
}