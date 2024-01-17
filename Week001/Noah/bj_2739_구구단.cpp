#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num;
    cin >> num;

    for(int i = 1; i < 10; i++){
        printf("%d * %d = %d\n", num, i, (num*i));
    }

    return 0;
}