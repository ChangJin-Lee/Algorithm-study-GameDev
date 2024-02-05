#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    list<char> l(s.begin(), s.end());

    list<char>::iterator cur = end(l);

    int n;
    cin >> n;

    while(n--)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L')
        {
            if(cur != begin(l)){
                cur--;
            }
        }
        else if (cmd == 'D')
        {
            if(cur != end(l)){
                cur++;
            }
        }
        else if (cmd == 'B')
        {
            if(cur != begin(l)){
                cur = l.erase(--cur);
            }
        }
        else if (cmd == 'P')
        {
            char input;
            cin >> input;
            l.insert(cur, input);
        }
    }

    while(!l.empty()){
        cout << l.front();
        l.pop_front();
    }

    return 0;
}