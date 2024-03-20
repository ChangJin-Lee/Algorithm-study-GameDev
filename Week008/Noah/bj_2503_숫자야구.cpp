#include <iostream>
#include <string>

using namespace std;

bool ans[988] = {true};

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void setTrue();
void isValidNum();

int main(){
    fastcpp;

    int n;
    cin >> n;

    setTrue();

    int guess[n];
    int strike[n];
    int ball[n];

    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> guess[i] >> strike[i] >> ball[i];
    }

    isValidNum();

    for(int i = 123; i <= 987; i++){

        for(int j = 0; j < n; j++){
            int s_cnt = 0;
            int b_cnt = 0;

            if(ans[i]){
                string temp = to_string(i);
                string temp2 = to_string(guess[j]);

                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(k == l && temp[k] == temp2[l]){
                            s_cnt++;
                        }
                        if(k != l && temp[k] == temp2[l]){
                            b_cnt++;
                        }
                    }
                }

                if(s_cnt != strike[j] || b_cnt != ball[j]){
                    ans[i] = false;
                }
            }
        }
    }

    for(int i = 123; i <= 987; i++){
        if(ans[i]){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}

void setTrue(){
    for(int i = 123; i <= 987; i++){
        ans[i] = true;
    }
}

void isValidNum(){
    for(int i = 123; i <= 987; i++){
        string temp = to_string(i);
        if(temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0]){
            ans[i] = false;
        }
        if(temp[0] == '0' || temp[1] == '0' || temp[2] == '0'){
            ans[i] = false;
        }
    }
}
