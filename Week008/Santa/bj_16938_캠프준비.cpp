#include <iostream> 
#include <map> 
#include <vector>

using namespace std;


int n, l ,r, x, d, num;

int minP, maxP; 
vector<pair<int, bool> > problems;


void collectProblem(int index)
{

    // 문제 난이도의 합이 l보다 작거나 r보다 크거나 
    if(d < l || d > r) return;

    // 쉬운 난이도와 어려운 난이도의 차이가 x보다 작을 경우
    if(maxP - minP < x) return;
    
    // 모든 조건에 맞았을 때 문제 출제 가짓수 1 증가
    num++;
    
    return;

    for(int idx = 0; idx < problems.size(); idx++)
    {
        // 이미 확인한 문제는 넘기기 
        if(problems[idx].second) continue;

        collectedProblems.push_back(problems[idx].first);   
        problems[idx].second = true;

        collectProblem(index++);

        problems[idx].second = false;
        collectedProblems.pop_back();
    }

}


int main()
{
    cin >> n >> l >> r >> x;

    for(int idx = 0; idx < n; idx++)
    {
        cin >> num;
        problems.push_back({num, false});
    }   

    num = 0;

    // 문제를 난이도 순서대로 정렬
    sort(problems.begin(), problems.end());

    collectProblem(0);

    return 0;
}