#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<int> s;
    vector<char> answer;
    int n;
    cin >> n;

    int cnt = 1;

    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        while(cnt <= input)
        {
            s.push(cnt);
            answer.push_back('+');
            cnt++;
        }

        if(input != s.top()){
            cout << "NO\n";
            return 0;
        }

        s.pop();
        answer.push_back('-');
    }

    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}