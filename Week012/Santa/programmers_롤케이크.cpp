#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    
    vector<int> cheolsoo(10001);
    vector<int> brother(10001);
    int cheolsooCount = 0;
    int brotherCount = 0;
    int answer = 0;
    
    for(int idx = 0; idx < topping.size(); ++idx)
    {
        if(brother[topping[idx]] == 0)
            brotherCount++;
        
        brother[topping[idx]]++;
    }
    
    for(int idx = 0; idx < topping.size(); ++idx)
    {
        if(cheolsoo[topping[idx]] == 0) 
            cheolsooCount++;
        
        cheolsoo[topping[idx]]++;
        brother[topping[idx]]--;
        
        if(brother[topping[idx]] == 0)
            brotherCount--;
        
        if(cheolsooCount == brotherCount)
            answer++;
    }
    
    return answer;
}



int main ()
{
    return 0;
}

