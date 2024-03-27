#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int n, l ,r, x, cnt; 
int checkedNums [16];
vector<int> problems;


void collectProblem(int idxP, int minNum, int maxNum, int ttl)
{
    // 문제의 합이 R보다 클 경우 탈출
    if(ttl > r) 
    {
        return;
    }
    //문제의 합이 L보다 클 경우 확인
    if(ttl >= l)
    {
        // 쉬운 난이도와 어려운 난이도의 차이가 x보다 클 경우
        if(maxNum - minNum >= x)
        {
            cnt++;
        }
    }

    // 시작 인덱스부터 다음 인덱스들의 문제들을 확인한다. 
    for(int idx = idxP; idx < n; idx++)
    {
         if(checkedNums[idx]) continue;

        checkedNums[idx] = true;
        // 현재 확인한 인덱스
        collectProblem(idx + 1, min(minNum, problems[idx]), max(maxNum, problems[idx]), ttl + problems[idx]);
        checkedNums[idx] = false;
    }
}


int main()
{
    cin >> n >> l >> r >> x;

    problems.assign(n, 0);

    for(int idx = 0; idx < n; idx++)
    {
        cin >> problems[idx];
    }   
   
    collectProblem(0, INT_MAX, 0, 0);
 
    cout << cnt;

    return 0;
}