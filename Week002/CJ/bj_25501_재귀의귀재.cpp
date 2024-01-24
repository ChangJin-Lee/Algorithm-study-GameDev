#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

// call by ref 로 해야 시간초과가 안남. 주소값 하나만 넘기기 때문.
int Recursion(const string &s, int l, int r);
int IsPalindrome(const string &s, int &recursionCnt);

int main()
{
    fastcpp;
    int t = 0;
    int recursionCnt = 0;
    string input = "";

    cin >> t;

    while(t--)
    {
        cin >> input;
        cout << IsPalindrome(input, recursionCnt) << " " << recursionCnt << "\n";
        recursionCnt = 0;
    }
}

int Recursion(const string &s, int l, int r, int &recursionCnt)
{
    recursionCnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return Recursion(s, l+1, r-1, recursionCnt);
}

int IsPalindrome(const string &s, int &recursionCnt)
{
    return Recursion(s, 0, s.length() - 1, recursionCnt);
}