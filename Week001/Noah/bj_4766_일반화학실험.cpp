#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<float> degree;
    int cnt = 0;

    while(1){
        float input;
        cin >> input;

        if(input == 999){
            break;
        }

        degree.push_back(input);
    }

    for(int i = 1; i < degree.size(); i++){
        // printf("%.2f\n", (degree[i] - degree[i-1]));
        cout << fixed;
        cout.precision(2);
        cout << degree[i] - degree[i-1] << "\n";
    }

    return 0;
}