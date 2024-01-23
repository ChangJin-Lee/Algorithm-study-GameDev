#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

// n개의 원판을 빈 공간에 옮기는 이동 횟수를 f(n) 이라고 하자.
// 점화식을 구해보면 다음과 같다.
// f(n) = 2*f(n-1) + 1
// f(1) = 1

// 수행 과정은 1,2,3번 으로의 과정을 재귀함수로 나타내면 된다.
// n개의 원판을 옮긴다고 하자. 
// 1. n-1개의 원판을 3으로 옮기고 (1 3)
// 2. 긴 원판을 2로 옮기고 (1 2)
// 3. n-1개의 원판을 1로 옮기고 (3 1)
// 4. 긴 원판을 3으로 옮기고 (2 3)
// 5. n-1개의 원판을 3으로 옮긴다 (1 3)
// 잘 생각해보면 처음 시작인 1번과 3번은 알고 있다. 
// 그럼 2번으로 옮긴다는건 어떻게 알까? -> 총 합은 6이니까 6에서 1번과 3번을 빼주면 된다.

int GetCount(int n);
void PrintLog(int startNum, int endNum, int n);

int main()
{
    fastcpp;
    int n = 0;

    cin >> n;

    cout << GetCount(n) << "\n";
    PrintLog(1,3,n);
}


int GetCount(int n)
{
    if( n == 1 )
    {
        return 1;
    }
    else
    {
        return 2 * GetCount(n-1) + 1;
    }
}

void PrintLog(int startNum, int endNum, int n)
{
    
    if( n == 1 )
    {
        cout << startNum << " " << endNum << "\n";
    }
    else
    {
        PrintLog(startNum, 6-startNum-endNum, n-1);
        cout << startNum << " " << endNum << "\n";
        PrintLog(6-startNum-endNum, endNum, n-1);
    }
}
