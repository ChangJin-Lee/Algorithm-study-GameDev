#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    vector<int> skill_pos(26, 0);
    
    for (int i = 0; i < skill.length(); i++) {
        skill_pos[skill[i] - 'A'] = i + 1;
    }
    
    int count = 0;
    
    for (const auto& tree : skill_trees) {
        int order = 1;
        bool valid = true;
        
        for (char c : tree) {
            int pos = skill_pos[c - 'A'];
            if (pos == 0) continue;
            if (pos == order) {
                order++;
            } else {
                valid = false;
                break;
            }
        }
        
        if (valid) count++;
    }
    
    return count;
}

int main() {
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}) << endl;
    return 0;
}
