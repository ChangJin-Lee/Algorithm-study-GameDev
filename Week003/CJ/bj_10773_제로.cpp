#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n = 0;
    int input = 0;
    int answer = 0;
    vector<int> v;
    
    cin >> n;
    for(int index = 0; index < n; index++)
    {
        cin >> input;
        if(input == 0)
        {
            v.pop_back();
        }
        else
        {
            v.push_back(input);
        }
    }
    
    for(int index = 0; index < v.size(); index++)
    {
        answer += v[index];
    }

    cout << answer;
}