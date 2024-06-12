#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<int> oddPulseSequence, evenPulseSequence;
    long long oddSum = 0;
    long long evenSum = 0;
    
    for(int i = 0 ; i < sequence.size(); i++)
    {
        if(i%2 == 0)
        {
            oddPulseSequence.push_back(-sequence[i]);
            evenPulseSequence.push_back(sequence[i]);
        }
        else
        {
            oddPulseSequence.push_back(sequence[i]);
            evenPulseSequence.push_back(-sequence[i]);
        }
    }
    
    for(int k : oddPulseSequence)
    {
        if(k > 0)
        {
            oddSum += k;
        }
        else
        {
            if(oddSum + k > 0)
            {
                oddSum += k;
            }
            else
            {
                oddSum = 0;
            }
        }
        
        if(oddSum > answer)
        {
            answer = oddSum;
        }
    }
    
    for(int k : evenPulseSequence)
    {
        if(k > 0)
        {
            evenSum += k;
        }
        else
        {
            if(evenSum + k > 0)
            {
                evenSum += k;
            }
            else
            {
                evenSum = 0;
            }
        }
        
        if(evenSum > answer)
        {
            answer = evenSum;
        }
    }
    
    return answer;
}

// [2, 3, -6, 1, 3, -1, 2, 4]
// [-2, 3, 6, 1, -3, -1, -2, 4]
 
// [2, -3, -6, -1, 3, 1, 2, -4]
// 2 / 3 1 2