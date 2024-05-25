#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream iss(s);
    vector<int> numbers;
    int number;
    
    while (iss >> number) {
        numbers.push_back(number);
    }
    
    sort(numbers.begin(), numbers.end());
    answer = to_string(numbers.front()) + " " + to_string(numbers.back());
    
    return answer;
}