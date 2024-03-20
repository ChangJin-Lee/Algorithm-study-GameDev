#include <iostream>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int maxIsPrimes = 100001;
vector<int> primes;
vector<bool> isPrimes;
void SetPrimes();

int main()
{
    fastcpp;
    int t,n;
    
    isPrimes.assign(maxIsPrimes,false);
    SetPrimes();

    cin >> t;

    while(t--)
    {
        int minDiff = maxIsPrimes;
        int left, right;
        cin >> n;

        for(int i = 0; i < primes.size()/2; i++)
        {
            for(int j = i; j < primes.size(); j++)
            {
                if(n < primes[i] + primes[j])
                {
                    break;
                }
                else if(n == primes[i] + primes[j])
                {
                    if(minDiff > primes[j] - primes[i])
                    {
                        left = primes[i];
                        right = primes[j];
                    }
                }
            }
        }
        cout << left << " " << right << "\n";
    }
}

void SetPrimes()
{
    for(int i = 2; i < maxIsPrimes; i++)
    {
        if(!isPrimes[i])
        {
            primes.push_back(i);
            for(int j = i; j < maxIsPrimes; j+=i)
            {
                isPrimes[j] = true;
            }
        }
    }
}