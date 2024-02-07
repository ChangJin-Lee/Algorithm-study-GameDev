#include <iostream>
#include <list>
#include <string>
#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main()
{
    fastTime;

    int testCase = 0;
    string input = "";

    list <char> myList;
    list<char>::iterator iter = myList.begin();

    cin >> testCase;

    for(int test = 0; test < testCase; test++)
    {
        cin >> input;

        for(char letter : input)
        {
            if(letter == '<')
            {
                if(iter != myList.begin())
                {
                    iter--;
                }
            }
            else if(letter == '>')
            {
                if(iter != myList.end())
                {
                    iter++;
                }
            }
            else if(letter == '-')
            {
                if(iter != myList.begin())
                {
                    iter = myList.erase(--iter);
                }
            }
            else
            {
                iter = myList.insert(iter, letter);
                iter++;
            } 

            // cout << "iter is " << *iter << '\n';
        }

        for(char letter : myList)
        {
            cout << letter; 
        }

        myList.clear();
        iter = myList.begin();

        cout << '\n';
    }

    return 0;
}