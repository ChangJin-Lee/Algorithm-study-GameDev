#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num_of_iter;
    cin >> num_of_iter;

    int cy_score = 100, sd_score = 100;

    for(int i = 0; i < num_of_iter; i++){
        int cy_input, sd_input;
        cin >> cy_input;
        cin >> sd_input;

        if(cy_input > sd_input){
            sd_score -= cy_input;
        }else if(cy_input < sd_input){
            cy_score -= sd_input;
        }else{
            continue;
        }
    }

    cout << cy_score << endl << sd_score;

    return 0;
}