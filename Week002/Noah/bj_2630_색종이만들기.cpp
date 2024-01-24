#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;
vector<int> v2;
int w_cnt = 0, b_cnt = 0;

void divCon(int row, int col, int len){
    int cnt = 0;
    for(int i = row; i < row + len; i++){
        for(int j = col; j < col + len; j++){
            if(v[i][j] == 1){
                cnt++;
            }
        }
    }
    
    if(cnt == 0){
        w_cnt++;
    }else if(cnt == len*len){
        b_cnt++;
    }else{
        divCon(row, col, len/2);
        divCon(row, col + len/2, len/2);
        divCon(row + len/2, col, len/2);
        divCon(row + len/2, col + len/2, len/2);
    }

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    // Get input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int input;
            cin >> input;
            v2.push_back(input);
        }
        v.push_back(v2);
        v2.clear();
    }

    divCon(0, 0, n);
    cout << w_cnt << "\n";
    cout << b_cnt << "\n";    

    return 0;
}