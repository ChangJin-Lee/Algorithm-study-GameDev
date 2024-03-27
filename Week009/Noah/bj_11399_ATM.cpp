#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n;
    cin >> n;

    vector<int> v(n);   // 시간
    vector<int> sum(n); // 누적합
    int totalSum = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    sum[0] = v[0];

    for(int i = 1; i < n; i++){
        sum[i] = sum[i - 1] + v[i];
    }

    for(int i = 0; i < n; i++){
        totalSum += sum[i];
    }

    cout << totalSum;

    return 0;
}