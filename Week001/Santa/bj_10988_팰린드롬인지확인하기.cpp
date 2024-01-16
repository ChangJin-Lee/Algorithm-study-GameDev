#include <iostream>
using namespace std; 

int main()
{
    string s; 
    int l = 0; 

    cin >> s; 
    l = s.length();

    for(int i = 0; i < l / 2; i++)
    {
        if(s[i] != s[l - 1 - i])
        {   
            cout << '0';
            return 0;
        }
    }
    
    cout << '1';

    return 0;
}