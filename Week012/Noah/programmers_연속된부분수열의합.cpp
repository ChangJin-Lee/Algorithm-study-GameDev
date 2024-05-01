#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, int(sequence.size())};
    int sum = 0;
    int r = -1;
    int l = 0;
    
    while(true){
        if(sum < k){
            r++;
            if(r >= sequence.size()){
                break;
            }
            sum += sequence[r];
        }else{
            sum -= sequence[l];
            if(l >= sequence.size()){
                break;
            }
            l++;
        }
        if(sum == k){
            if(r - l == 0){
                answer[1] = r;
                answer[0] = l;
                break;
            }
            if(answer[1] - answer[0] > r - l){
                answer[1] = r;
                answer[0] = l;
            }
        }
    }
    
    return answer;
}