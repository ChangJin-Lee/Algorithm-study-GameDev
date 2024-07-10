#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
        
    while(n > 0)
    {
        int temp = n % 3;
        
        switch(temp)
        {
            case 1 : 
                answer += "1";
                break;
            
            case 2 : 
                answer += "2";
                break;
                
            case 0 : 
                answer += "4";
                n -= 1;
                break;
        }
        n /= 3;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}