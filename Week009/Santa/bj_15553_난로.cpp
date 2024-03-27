#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> inputHours;
vector<int> stoves;

int main() 
{
    int n, k, before, result = 1;

    cin >> n >> k;

    stoves.assign(n-1,0);
    inputHours.assign(n,0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> inputHours[idx];
    }

    for(int idx = 0; idx < n-1; idx++)
    {
        stoves[idx] = inputHours[idx+1] - inputHours[idx];
    }

    sort(stoves.begin(), stoves.end());

    for(int idx = 0; idx < n-k; idx++)
    {
        result += stoves[idx];
    }

    cout << result + k-1;
} 
