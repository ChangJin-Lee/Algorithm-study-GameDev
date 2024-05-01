#include <string>
#include <vector>
#include <iostream>

using namespace std; 


int solution(string skill, vector<string> skill_trees) {
    
    vector <int> prerequisiteSkill(26);
    
    for(int idx = 0; idx < skill.length(); idx++)
    {
        prerequisiteSkill[skill[idx]] = idx + 1;
    }
    
    int answer = 0;
    
    for(int order = 0; order < skill_trees.size(); order++)
    {
        string checkSkill = skill_trees[order];
        int skillOrder = 1;
        bool isPossible = true;
        
        for(int idx = 0; idx < checkSkill.length(); idx++)
        {
            if(prerequisiteSkill[checkSkill[idx]] == 0)
                continue;
            
            if(prerequisiteSkill[checkSkill[idx]] == skillOrder)
            {
                skillOrder++;
                continue;
            }
                
            if(prerequisiteSkill[checkSkill[idx]] != skillOrder)
            {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible)
            answer++;
    }
    
    
    return answer;
}



int main()
{
    return 0;
}