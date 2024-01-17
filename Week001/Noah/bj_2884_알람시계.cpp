#include <iostream>

using namespace std;

int main(){
    ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int hour, min;
    cin >> hour;
    cin >> min;

    if(min < 45){
        min += 15;
        if(hour == 0){
            hour = 23;
        }else{
            hour -= 1;
        }
    }else{
        min -= 45;
    }

    cout << hour << " " << min << endl;

    return 0;
}