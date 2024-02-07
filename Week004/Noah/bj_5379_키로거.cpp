#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    list<char> l;
    list<char>::iterator cur = l.end();
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<')
            {
                if (cur != l.begin())
                {
                    cur--;
                }
            }
            else if (s[i] == '>')
            {
                if (cur != l.end())
                {
                    cur++;
                }
            }
            else if (s[i] == '-')
            {
                if (cur != l.begin())
                {
                    cur = l.erase(--cur);
                }
            }
            else
            {
                l.insert(cur, s[i]);
            }
        }

        while(!l.empty()){
            cout << l.front();
            l.pop_front();
        }

        l.clear();
        cur = l.end();
        cout << "\n";
    }

    return 0;
}