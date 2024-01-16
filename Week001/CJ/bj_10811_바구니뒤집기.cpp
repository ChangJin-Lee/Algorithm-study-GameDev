#include <iostream>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

void ReverseSection(vector<int>& v, int i, int j)
{
    vector<int> tmp(j-i+1,0);
    
    for(int index = i; index < j+1; index++)
    {
        tmp[index-i] = v[index];
    }
    reverse(tmp.begin(), tmp.end());

    for(int index = i; index < j+1; index++)
    {
        v[index] = tmp[index-i];
    }
}

int main()
{
    fastcpp;
    int n, m;
    int i,j;
    cin >> n >> m;
    vector<int> v(n,0);

    for (int index=0; index < n; index++)
    {
        v[index] = index+1;
    }

    for (int index=0; index < m; index++)
    {
        cin >> i >> j;
        ReverseSection(v, i-1, j-1);
    }

    for (auto k : v)
    {
        cout << k << " ";
    }
}

