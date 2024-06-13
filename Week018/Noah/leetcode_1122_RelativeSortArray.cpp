class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> answer;
        // key: elements in arr2, value: number of elements in arr1
        map<int, int> m;
        
        for(int i = 0; i < arr1.size(); ++i){
            if(m.find(arr1[i]) == m.end()){
                m[arr1[i]] = 1;
            }else{
                m[arr1[i]]++;
            }
        }
        
        for(int i = 0; i < arr2.size(); ++i){
            while(m[arr2[i]] > 0){
                answer.push_back(arr2[i]);
                m[arr2[i]]--;
            }
        }
        
        int temp = answer.size();
        
        for(int i = 0; i < arr1.size(); ++i){
            if(m[arr1[i]] != 0){
                while(m[arr1[i]] > 0){
                    answer.push_back(arr1[i]);
                    m[arr1[i]]--;
                }
            }
        }
        
        for(int i = 0; i < answer.size(); ++i){
            cout << answer[i] << " ";
        }
        
        sort(answer.begin() + temp, answer.end());
        
        return answer;
    }
};