#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if('a' <= str[i] && str[i] <= 'z')
        {
            cout << (char)toupper(str[i]);
        }
        else
        {
            cout << (char)tolower(str[i]);
        }
    }
    return 0;
}