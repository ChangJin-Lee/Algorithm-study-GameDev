#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    return a[1] > b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<int> wanho = scores[0];
    vector<bool> IsIncentive(scores.size(), true);
    
    int maxVal = 0;
    
    sort(scores.begin(), scores.end(), compare);
    
    for(int i = scores.size()-1 ; i >= 0 ; i--)
    {
        if(scores[i][0] > wanho[0] && scores[i][1] > wanho[1])
        {
            return -1;
        }
        
        if(maxVal > scores[i][1])
        {
            IsIncentive[i] = false;
        }
        else
        {
             maxVal = scores[i][1];
        }
    }
    
    for(int i = 0 ; i < scores.size(); i++)
    {
        if(IsIncentive[i] && scores[i][0] + scores[i][1] > wanho[0] + wanho[1])
        {
            answer++;
        }
    }
    
    return answer;
}