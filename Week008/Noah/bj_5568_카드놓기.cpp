#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
vector<string> cards;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        cards.push_back(temp);
    }

    sort(cards.begin(), cards.end());

    set<string> ans;

    do{
        string s = "";
        for(int i = 0; i < k; i++){
            s += cards[i];
        }
        ans.insert(s);
    }while(next_permutation(cards.begin(), cards.end()));

    cout << ans.size();

    return 0;
}
