#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int x = 1; x <= r2; ++x){
        int maxY = floor(sqrt(pow(r2, 2) - pow(x, 2)));
        int minY = ceil(sqrt(pow(r1, 2) - pow(x, 2)));
        
        if(x < r1){
            answer += maxY - minY + 1;
        }else{
             answer += maxY + 1;
        }
    }
    
    return answer * 4;
}