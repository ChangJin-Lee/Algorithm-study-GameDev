#include <iostream>
#include <vector>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int start = 0, end = 0;
    int sum = v[0];
    int cnt = 0;

    while(end < n && start <= end){
        if(sum < m){
            sum += v[++end];
        }else if(sum > m){
            sum -= v[start];
            ++start;
            if(start > end){
                end = start;
                sum = v[end];
            }
        }else{
            ++cnt;
            sum += v[++end];
            sum -= v[start];
            ++start;
        }
    }

    cout << cnt;

    return 0;
}