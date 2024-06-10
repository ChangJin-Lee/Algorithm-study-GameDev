class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> answer;
        vector<int> frequency(26, INT_MAX);
        
        for(int i = 0; i < words.size(); ++i){
            vector<int> charCount(26);
            for(char c : words[i]){
                charCount[c - 'a']++;
            }
            
            for(int j = 0; j < 26; ++j){
                frequency[j] = min(frequency[j], charCount[j]);
            }
        }
        
        for(int i = 0; i < 26; ++i){
            while(frequency[i] > 0){
                answer.push_back(string(1, 'a' + i));
                frequency[i]--;
            }
        }
        
        return answer;
    }
};