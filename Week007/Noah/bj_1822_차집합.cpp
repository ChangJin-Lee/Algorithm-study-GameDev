#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vA;
vector<int> vB;
priority_queue<int, vector<int>, greater<int> > ans;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    int nA, nB;
    cin >> nA >> nB;

    for(int i = 0; i < nA; i++){
        int temp;
        cin >> temp;
        vA.push_back(temp);
    }

    for(int i = 0; i < nB; i++){
        int temp;
        cin >> temp;
        vB.push_back(temp);
    }

    sort(vB.begin(), vB.end());

    for(int i = 0; i < nA; i++){
        if(!binary_search(vB.begin(), vB.end(), vA[i])){
            ans.push(vA[i]);
        }
    }

    if(ans.empty()){
        cout << 0;
    }else{
        cout << ans.size() << "\n";
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }

    return 0;
}