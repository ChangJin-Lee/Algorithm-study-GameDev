#include <iostream>

using namespace std; 

int main()
{
    int input = 0;
    int masterpiece [6] = {1, 1, 2, 2, 2, 8};

    for(int i = 0; i < 6; i++)
    {
        cin >> input;
        masterpiece[i] -= input;
    }

    for(int i = 0; i < 6; i++)
    {
        cout << masterpiece[i] << " ";
    }

    return 0;
}