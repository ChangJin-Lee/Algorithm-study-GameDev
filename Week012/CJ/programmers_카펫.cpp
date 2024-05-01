#include <string>
#include <vector>

using namespace std;

class Carpet
{
public:
    int dimension;
    int brown;
    int yellow;
    vector<int> PossiblCoordinate;

    Carpet(int x, int y);

    void CalculatePossibleSituation();
    vector<int> GetAnswer();
};

Carpet::Carpet(int x, int y)
{
    this->dimension = x + y;
    this->brown = x;
    this->yellow = y;
}

inline void Carpet::CalculatePossibleSituation()
{

    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            PossiblCoordinate.push_back(i);
        }
    }
}

vector<int> Carpet::GetAnswer()
{
    CalculatePossibleSituation();
    for (auto x : PossiblCoordinate)
    {
        for (auto y : PossiblCoordinate)
        {
            if (x * y == yellow && (x + 2) * (y + 2) == dimension)
            {
                return {max(x+2,y+2), min(x+2,y+2)};
            }
        }
    }
}

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    Carpet carpet(brown, yellow);
    answer = carpet.GetAnswer();
    return answer;
}