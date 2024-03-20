#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n, m;
vector<int> nums;
int arr[8];


void backTracking(int idx)
{
    if(idx == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        arr[idx] = nums[i];

        backTracking(idx + 1);
    }
}




int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int num = 0;

        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    backTracking(0);

    return 0;
}