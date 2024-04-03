#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std; 

vector<int> myV;

int main()
{
    int n; 
    int ans = 4; // 5개의 연속된 숫자의 차이는 4임  1,2,3,4,5 (5-1) 

    cin >> n;

    myV.assign(n,0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> myV[idx];
    }

    sort(myV.begin(), myV.end());

    for(int st = 0; st < n; st++)
    {
        int en = n - 1;
        while(st < en)
        {  
            // 두 수 사이의 숫자의 갯수가 5개보다 많을 때 en을 옮김
            if(myV[en] - myV[st] > 4) 
            {
                en--;
            }
            else
            {
                //idx en과 st의 사이에 있는 숫자의 갯수에 연속된 숫자의 차를 뺀것을 비교
                ans = min(ans, 4 - (en - st));
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
