#include <string>
#include <vector>

using namespace std;

int answer = 0;

class SearchTarget
{
    public : 
    int target;
    vector<int> *numbers;

    SearchTarget(vector<int> *numbers, int target)
    {
        this->numbers = numbers;
        this->target = target; 
    }
 
    void DFS(int idx, int result);
};

void SearchTarget::DFS(int idx, int result)
{
    if(idx == numbers->size())
    {
        if(result == target) 
            answer += 1;
        return; 
    }

    DFS(idx + 1, result + (*numbers)[idx]);
    DFS(idx + 1, result - (*numbers)[idx]);
    return;
}



int solution(vector<int> numbers, int target) {
    SearchTarget SearchTarget(&numbers, target);

    SearchTarget.DFS(0, 0);
    return answer;
}