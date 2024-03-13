#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> v;
int ans = 200000001;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main() {
    fastcpp;
    int n;
    cin >> n;

    while(n--){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int>::iterator iter = v.begin();
    vector<int>::iterator iter2 = v.end() - 1;

    while(!(iter >= iter2)){
        int temp = *iter + *iter2;
        if(temp == 0){
            cout << 0;
            return 0;
        }else if(temp > 0){
            if(abs(temp) < abs(ans)){
                ans = temp;
            }
            iter2--;
        }else{
            if(abs(temp) < abs(ans)){
                ans = temp;
            }
            iter++;
        }
    }

    cout << ans;

    return 0;
}