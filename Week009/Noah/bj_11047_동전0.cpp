#include <iostream>
#include <vector>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n, k;
    cin >> n >> k;

    vector<int> v;
    int ans = 0;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = n - 1; i >= 0; i--){
        ans += k / v[i];
        k %= v[i];
    }

    cout << ans;

    return 0;
}