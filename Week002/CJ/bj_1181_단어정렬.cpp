#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

bool compare(string x, string y);

int main()
{
    fastcpp;
    int n = 0;
    string input;
    vector<string> v;

    cin >> n;

    for(int index = 0; index < n; index++)
    {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), compare);
    
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto k : v)
    {
        cout << k << "\n";
    }
}

bool compare(string x, string y)
{
    return x.length() == y.length() ? x < y : x.length() < y.length(); 
}