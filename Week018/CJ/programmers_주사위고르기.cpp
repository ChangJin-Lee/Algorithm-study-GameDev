#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> depthArray;
vector<vector<int>> tables;

void Combination(int n, int r, int cur, int depth)
{
    if(depth == r)
    {
        tables.push_back(depthArray);
        return;
    }
    
    for(int i = cur; i < n; ++i)
    {
        depthArray[depth] = i;
        Combination(n, r, i+1, depth+1);
    }
}


vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int maxVal = 0;
    int n = dice.size();
    int r = n / 2;
    
    depthArray.resize(r, 0);
    Combination(n, r, 0, 0);
    
    for(vector<int> &table : tables)
    {
        vector<int> bTable;
        
        for(int i = 0; i < n; ++i)
        {
            if(find(table.begin(), table.end(), i) == table.end())
            {
                bTable.push_back(i);
            }
        }
        
        vector<int> aCases = dice[table[0]];
        vector<int> bCases = dice[bTable[0]];

        for(int i = 1; i < table.size(); ++i)
        {
            vector<int> temp;
            for(int j : dice[table[i]])
            {
                for(int acase : aCases)
                {
                    temp.push_back(acase + j);
                }
            }
            aCases = temp;
        }
        
        for(int i = 1; i < bTable.size(); ++i)
        {
            vector<int> temp;
            for(int j : dice[bTable[i]])
            {
                for(int bcase : bCases)
                {
                    temp.push_back(bcase + j);
                }
            }
            bCases = temp;
        }
        
        int winCaseCount = 0;
        
        for(int acase : aCases)
        {
            for(int bcase : bCases)
            {
                if(acase > bcase)
                {
                    winCaseCount++;
                }
            }
        }
        
        
        if(winCaseCount > maxVal)
        {
            maxVal = winCaseCount;
            answer.clear();
            for(int t : table)
            {
                answer.push_back(t+1);
            }
        }
    }
    
    return answer;
}