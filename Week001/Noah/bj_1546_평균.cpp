//
// Created by 이승용 on 1/17/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num_of_class;
    int max_score = 0;
    cin >> num_of_class;

    vector<int> scores;
    float result;

    for(int i = 0; i < num_of_class; i++){
        float input;
        cin >> input;
        scores.push_back(input);
    }

    result = accumulate(scores.begin(), scores.end(), 0.0) / *max_element(scores.begin(), scores.end()) * 100 / num_of_class;

    printf("%f \n", result);

    return 0;
}