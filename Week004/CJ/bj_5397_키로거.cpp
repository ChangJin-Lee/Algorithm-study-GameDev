#include <iostream>
#include <string>
#include <list>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main()
{
    fastcpp;
    int n;
    list<char> f;
    list<char> b;
    string input;

    cin >> n;

    while(n--)
    {
        cin >> input;
        f.clear();
        b.clear();
        
        for ( auto k : input )
        {

            if( k == '<' )
            {
                if(!f.empty())
                {
                    b.push_back(f.back());
                    f.pop_back();
                }
            }
            else if ( k == '>' )
            {
                if(!b.empty())
                {
                    f.push_back(b.back());
                    b.pop_back();
                }
            }
            else if ( k == '-' )
            {
                if(!f.empty())
                {
                    f.pop_back();
                }
            }
            else
            {
                f.push_back(k);
            }
        }

        for(auto k : f)
        {
            cout << k;
        }

        b.reverse();
        for(auto k : b)
        {
            cout << k;
        }
        cout << "\n";
    }
}