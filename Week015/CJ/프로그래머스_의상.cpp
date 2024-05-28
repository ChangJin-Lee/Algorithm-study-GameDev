#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, vector<string>> clothTypes;
    int multipleType = 1;

    for (const auto& cloth : clothes) {
        clothTypes[cloth[1]].push_back(cloth[0]);
    }

    for (const auto& clothType : clothTypes) {
        multipleType *= (clothType.second.size() + 1);
    }

    return multipleType - 1;
}