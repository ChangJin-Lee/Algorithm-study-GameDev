#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    int DP[n];
    
    DP[0] = 1;
    DP[1] = 2;
    
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }
    
    for(int i = 2; i < n; ++i){
        DP[i] = DP[i - 2] % 1234567 + DP[i - 1] % 1234567;
    }
    
    return DP[n - 1] % 1234567;
}