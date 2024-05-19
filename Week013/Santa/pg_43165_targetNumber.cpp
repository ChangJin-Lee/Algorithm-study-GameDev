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
 
    void DFS(int depth, int value);
};

void SearchTarget::DFS(int depth, int value)
{
    if(depth == numbers->size())
    {
        if(value == target) 
            answer += 1;
        return; 
    }

    DFS(depth + 1, value + (*numbers)[depth]);
    DFS(depth + 1, value - (*numbers)[depth]);
}



int solution(vector<int> numbers, int target) {
    SearchTarget SearchTarget(&numbers, target);

    SearchTarget.DFS(0, 0);
    return answer;
}