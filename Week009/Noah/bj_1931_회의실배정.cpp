#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int n;
    cin >> n;

    // end time, start time
    vector<pair<int, int> > v;
    int cnt = 1;

    for(int i = 0; i < n; i++){
        int st, et;
        cin >> st >> et;
        v.push_back(make_pair(et, st));
    }

    // sort by endtime
    sort(v.begin(), v.end());
    int cur_et = v[0].first;

    for(int i = 1; i < n; i++){
        if(v[i].second >= cur_et){
            cnt++;
            cur_et = v[i].first;
        }
    }

    cout << cnt;

    return 0;
}