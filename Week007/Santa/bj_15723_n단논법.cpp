#include <iostream>
#include <vector>
#include <string>

using namespace std;

int box [27];
int idx1, idx2, testCase;
string blank;

void findLetter(int idx, int target)
{
    if(box[idx] == 0)
    {
        cout << 'F' << '\n';
        return;
    }
    if(box[idx] == target)
    {
        cout << 'T'<< '\n';
        return;
    }

    findLetter(box[idx], target);
}


int main()
{
    cin >> testCase;

    while(testCase--)
    {   
        char first, second;
        cin >> first >> blank >> second;

        idx1 = first - 96;
        idx2 = second - 96;
        
        box[idx1] = idx2;
    }

    cin >> testCase;

    while(testCase--)
    {
        char first, second;
        cin >> first >> blank >> second;

        idx1 = first - 96;
        idx2 = second - 96;

        findLetter(idx1, idx2);
    }

    return 0;
}