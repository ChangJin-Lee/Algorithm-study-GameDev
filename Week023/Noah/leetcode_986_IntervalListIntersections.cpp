class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        
        while(i < size(firstList) && j < size(secondList)){
            if(firstList[i][1] >= secondList[j][0] && firstList[i][0] <= secondList[j][1]) {
                vector<int> temp;
                
                temp.push_back(max(firstList[i][0], secondList[j][0]));
                temp.push_back(min(firstList[i][1], secondList[j][1]));
                
                ans.push_back(temp);
            }

            firstList[i][1] < secondList[j][1] ? i++ : j++;
        }
        
        return ans;
    }
};