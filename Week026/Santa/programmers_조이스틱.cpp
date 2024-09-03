#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.length();
    int min_Move = n - 1;
    
    for(int i = 0; i < n; ++i)
    {
        int cnt = min(name[i] - 'A', 'Z' - name[i] + 1);
        answer += cnt; 
    
        int next = i + 1; 
        while(next < n && name[next] == 'A')
        {
            next++;
        }
    
        min_Move = min(min_Move, i + n - next + min(i, n - next));
    }
    
    answer += min_Move;
    
    return answer;
}