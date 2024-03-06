#include <iostream> 

using namespace std;

// x를 3으로 나누어 떨어지면 3으로 나눈다 
// x를 2로 나누어 떨어지면 2로 나눈다 
// 1을 뺀다 
// N을 1로 만드는 최소연산횟수

// 3이나 2로 나눠지지 않는 수의 최소 연산 횟수는 앞의 수의 +1 이다 
// DP에는 최소 연산 횟수를 저장하고 PATH에는 연산값을 저장하자
// DP의 값을 3으로 나눈값과, 2로 나눈값 중에 적은 값으로 계속 업데이트 한다 

int DP[1000001];
int PATH[1000001];

int main()
{
    int n = 0;
    cin >> n;

    // 1이 1으로 되는 연산횟수는 0이다. 
    DP[1] = 0;


    //  bottom-up 방식으로 1부터 n까지 계산해간다.
    for(int idx = 2; idx <= n; idx++)
    {
        // 3이나 2로 나눠지지 않는 숫자는 앞의 숫자의 연산횟수에 +1회 만큼이다. 
        DP[idx] = DP[idx - 1] + 1; 
        // 3이나 2로 나눠지지 않는 숫자의 첫번째 연산은 -1이다. 
        PATH[idx] = idx - 1;

        // 3으로 나눠지고 기존 연산 횟수보다 적다면 업데이트
        if(idx % 3 == 0 && DP[idx] > DP[idx / 3] + 1)
        {
            // 최소 연산 횟수
            DP[idx] = DP[idx / 3] + 1;

            // 연산 후 값
            PATH[idx] = idx / 3;
        }

        // 2로 나눠지고 기존 연산 횟수보다 적다면 업데이트
        if(idx % 2 == 0 && DP[idx] > DP[idx / 2] + 1)
        {
            // 최소 연산 횟수
            DP[idx] = DP[idx / 2] + 1;

            // 연산 후 값 
            PATH[idx] = idx / 2;
        }
    }


    cout << DP[n] << '\n';
    
    while(n != 0)
    {
        // n을 출력한다. 
        cout << n << ' ';

        // n의 연산 후 값을 출력
        n = PATH[n];
    }

    return 0;
}