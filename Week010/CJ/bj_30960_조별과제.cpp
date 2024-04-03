#include <iostream>
#include <vector>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main()
{
    fastcpp;
    int n,minVal;
    vector<int> v, subV;

    cin >> n;
    v.assign(n+1,0);
    subV.assign(n+1,0);
    minVal = 1000000001;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++)
    {
        subV[i] = v[i] - v[i-1];
        if(i >=2 )
            subV[i] += subV[i-2];
    }

    for (int i = n; i > 2; i-=2)
    {
        int subVal = v[i] - v[i-2];

        // cout << i << " " << subVal << " \n";

        // cout << subV[n] << " " << subV[i] << " " << subV[i-3] << " \n";
        
        subVal += subV[n] - subV[i] + subV[i-3];

        // cout << i << " " << subVal << " \n";

        minVal = min(minVal, subVal);
    }

    cout << minVal;

}


// 0 1 3 4 5 9

// 0 1 2 1 1 4

// 0 1 2 1 3 4

// 2 1
// 1 4

// 0 1 3 9 10 11 18 20

// 0 1 2 6 1 1 7 2

// 0 1 2 7 3 8 10 10
