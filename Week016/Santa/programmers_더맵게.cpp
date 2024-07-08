#include <string>
#include <vector>
#include <queue> 

using namespace std;

priority_queue<int, vector<int>, greater<int>> convertIntoQueue(vector<int>& target)
{
    priority_queue<int, vector<int>, greater<int>> myQ; 
    
    for(int n : target)
    {
        myQ.push(n);
    }
    
    return myQ;
}

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> myQ; 
    myQ = convertIntoQueue(scoville);
    
    while(myQ.top() < K)
    {
        int temp1 = myQ.top(); 
        myQ.pop();
        
        if(myQ.empty())
        {
            answer = -1;
            break;
        }
        
        int temp2 = myQ.top();
        myQ.pop();
        
        int temp3 = temp1 + temp2  * 2;
        myQ.push(temp3);
        
        answer++;
    }
    
    return answer;
}