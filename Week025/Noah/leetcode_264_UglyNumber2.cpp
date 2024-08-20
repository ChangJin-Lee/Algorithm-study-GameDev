class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_vec = {1};
        int t2 = 0, t3 = 0, t5 = 0;
        
        for(int i = 1; i < n; ++i){
            int second = ugly_vec[t2] * 2;
            int third = ugly_vec[t3] * 3;
            int fifth = ugly_vec[t5] * 5;
            
            ugly_vec.push_back(min(second, min(third, fifth)));
            
            if(ugly_vec[i] == second){
                t2++;
            }
            
            if(ugly_vec[i] == third){
                t3++;
            }
            
            if(ugly_vec[i] == fifth){
                t5++;
            }
        }
        
        return ugly_vec[n - 1];
    }
};