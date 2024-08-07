#include <algorithm>

using namespace std;

long long solution(int w, int h) {
    long long answer = 1;
    long long gcd = __gcd(w, h);
    
    answer = (long long)w * h - (w + h) + gcd;
    
    return answer;
}