#include <iostream>

using namespace std; 

int main()
{
    int n;
    char s = '*';

    cin >> n; 

    // 2 * n - 1

    for(int i = 1; i < n; i++)
    {
        for(int b = 0; b < n - i; b++)
        {
            cout << " ";
        }

        for(int j = 0; j < 2 * i - 1; j++)
        {
            cout << s;
        }
        cout << endl;
    }

    for(int i = n; i > 0; i--)
    {
       for(int b = 0; b < n - i; b++)
        {
            cout << " ";
        }

        for(int j = 0; j < 2 * i - 1; j++)
        {
            cout << s;
        }
        cout << endl;
    }

    return 0;
}