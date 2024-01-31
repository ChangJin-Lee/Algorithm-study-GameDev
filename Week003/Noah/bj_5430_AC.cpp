#include <iostream>
#include <deque>
#include <string>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
    fastcpp;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool isReverse = false;
        bool error = false;

        string s = "";
        string cmd, str;
        int num;
        deque<int> dq;
        cin >> cmd;
        cin >> num;
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            if (isdigit(str[j]))
            {
                s += str[j];
            }
            else
            {
                if (s != "")
                {
                    dq.push_back(stoi(s));
                    s.clear();
                }
            }
        }

        for (int j = 0; j < cmd.length(); j++)
        {
            if (cmd[j] == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    error = true;
                    break;
                }
                else
                {
                    if (isReverse == false)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
            }
        }

        if (error == false)
        {
            cout << "[";

            if (isReverse)
            {
                while(!dq.empty())
                {
                    if(dq.size() != 1){
                        cout << dq.back() << ",";
                    }else{
                        cout << dq.back();
                    }
                    dq.pop_back();
                }
            }
            else
            {
                while(!dq.empty())
                {
                    if(dq.size() != 1){
                        cout << dq.front() << ",";
                    }else{
                        cout << dq.front();
                    }
                    dq.pop_front();
                }
            }

            cout << "]\n";
        }
    }

    return 0;
}