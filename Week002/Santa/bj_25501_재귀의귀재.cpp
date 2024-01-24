#include <iostream>
#include <string>
#define fastTime ios::snyc_withstdio(false), cin.tie(0);

using namespace std;

int functionCount = 1;

int isPalindrome(string& str, int front, int end)
{
    if(front >= end)
    {
        return 1;
    }

    else if(str[front] != str[end])
    {
        return 0;
    }

    else
    {
        functionCount++;
        return isPalindrome(str, front + 1, end - 1);
    }
}


int main()
{
    int testCase = 0;
    string testWord = "";

    cin >> testCase;

    for(int input = 0; input < testCase; input++)
    {
        cin >> testWord; 
        cout << isPalindrome(testWord, 0, testWord.length() - 1) << ' ' << functionCount << '\n';
        functionCount = 1;
    }
    return 0;
}