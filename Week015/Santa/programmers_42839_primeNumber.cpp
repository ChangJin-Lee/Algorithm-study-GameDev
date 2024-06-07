#include <string>
#include <vector>
#include <set> 
#include <algorithm> 
#include <cmath> 

using namespace std;

bool isPrime(int target)
{
    for(int n = 2; n <= sqrt(target); ++n)
    {
        if(target % n == 0)
            return false;
    }
    return true;
}

int stringToInt(string nums)
{
    int num = 0;
    for(char c : nums)
    {
        num = num * 10 + (c - '0');
    }
    return num;
}

int solution(string numbers) {
    set<int> mySet; 
    sort(numbers.begin(), numbers.end());
    
    do
    {
        for(int idx = 1; idx < numbers.length() + 1; ++idx)
        {
            string tempString = numbers.substr(0, idx);
            int tempInt = stringToInt(tempString);

            if(tempInt <= 1) continue;
            
            if(isPrime(tempInt))
            {
                mySet.insert(tempInt);
            }    
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return mySet.size();
}