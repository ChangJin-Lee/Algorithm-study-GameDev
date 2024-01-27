#include <iostream>
#include <vector>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void ReversePrint(vector<char> &v);
void ForwardPrint(vector<char> &v);

int main()
{
    fastcpp;
    bool forwardCheck = false;
    string input;
    vector<char> v;
    char cur;

    getline(cin, input);

    for(int index = 0; index < input.length()+1; index++)
    {
        cur = input[index];
        switch (cur)
        {
            case '<':
                forwardCheck = true;
                if(v.size() != 0)
                    ReversePrint(v);
                cout << cur;
                break;
            case '>':
                forwardCheck = false;
                ForwardPrint(v);
                break;
            case ' ':
                if(!forwardCheck)
                {
                    ReversePrint(v);
                    cout << ' ';
                }
                else
                    v.push_back(cur);
                break;
            default:
                if(index == input.length())
                    ReversePrint(v);
                v.push_back(cur);
                break;
        }
    }
}

void ReversePrint(vector<char> &v)
{
    for(int index = v.size() - 1; index >= 0; index--)
    {
        cout << v[index];
    }
    v.clear();
}

void ForwardPrint(vector<char> &v)
{
    for(int index = 0; index < v.size(); index++)
    {
        cout << v[index];
    }
    cout << '>';
    v.clear();
}