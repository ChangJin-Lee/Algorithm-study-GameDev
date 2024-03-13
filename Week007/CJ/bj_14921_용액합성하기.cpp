#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int main()
{
    fastcpp;
    int n, maxVal, answer;
    vector<int> v;

    cin >> n;

    v.assign(n,0);
    maxVal = 100000001;

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = n - 1;   

        while(left <= right)
        {
            int mid = (left + right) / 2;
            int sums = v[mid] + v[i];

            if(abs(sums) < maxVal)
            {
                answer = sums;
                maxVal = abs(sums);
            }

            if(sums < 0)
            {
                left = mid + 1;
            }
            else if (sums >= 0)
            {
                right = mid - 1;
            }
        }
    }

    cout << answer;

}