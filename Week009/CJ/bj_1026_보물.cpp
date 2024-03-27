#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

bool compare(int x, int y);

int main()
{
    fastcpp;
    int n, m, input;
    int answer = 0;
    vector<int> A, B;

    cin >> n;

    
    m = n;
    while(m--)
    {
     cin >> input;
     A.push_back(input);
    }
    m = n;
    while(m--)
    {
     cin >> input;
     B.push_back(input);
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for( int i = 0; i < n; i++)
    {
        answer += A[i] * B[i];
    }

    cout << answer;
}

bool compare(int x, int y)
{
    return x > y;
}