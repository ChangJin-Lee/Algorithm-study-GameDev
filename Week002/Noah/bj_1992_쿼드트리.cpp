#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > v;
vector<int> v2;
string ans;

void divCon(int row, int col, int len){
    bool isSame = true;
    for(int i = row; i < row + len; i++){
        for(int j = col; j < col + len; j++){
            if(v[i][j] != v[row][col]){
                isSame = false;
                break;
            }
        }
        if(!isSame){
            break;
        }
    }

    if(!isSame){
        ans += "(";
        divCon(row, col, len/2);
        divCon(row, col + len/2, len/2);
        divCon(row + len/2, col, len/2);
        divCon(row + len/2, col + len/2, len/2);
        ans += ")";
    }else{
        ans += v[row][col];
    }

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < n; j++){
            
            v2.push_back((int)input[j]);
        }
        v.push_back(v2);
        v2.clear();
    }

    divCon(0, 0, n);

    cout << ans;

    return 0;
}