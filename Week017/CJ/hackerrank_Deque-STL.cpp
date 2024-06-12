#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n, k;
    cin >> t;
    
    while(t--)
    {
        vector<int> dq;
        vector<int> subDq;
        vector<int> answer;
        int maxVal = 0;
        cin >> n >> k;
        dq.resize(n,0);
        
        for(int i = 0; i < n; ++i)
        {
            cin >> dq[i];
        }
        
        for(int i = 0; i < k; ++i)
        {
            subDq.push_back(dq[i]);
        }
        maxVal = *max_element(subDq.begin(), subDq.end());
        answer.push_back(maxVal);
        
        for(int i = k; i < n; ++i)
        {
            int popedVal = subDq.front();
            subDq.erase(subDq.begin());
            subDq.push_back(dq[i]);
            
            if(popedVal == maxVal)
            {
                maxVal = *max_element(subDq.begin(), subDq.end());
            }
            if(dq[i] > maxVal)
            {
                maxVal = dq[i];
            }
            answer.push_back(maxVal);
        }
        
        for(int l : answer)
        {
            cout << l << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
