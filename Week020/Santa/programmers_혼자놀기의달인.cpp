#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsVisited [100];

int DFS(const vector<int>& cards, int Node, int Depth)
{
    if(IsVisited[Node]) return Depth;

    IsVisited[Node] = true;
    
    return DFS(cards, cards[Node] - 1, Depth + 1);
}



int solution(vector<int> cards) {
    int answer = 0;
    vector<int> CardLength(100);
    
    for(int idx = 0; idx < cards.size(); ++idx)
    {
        CardLength.push_back(DFS(cards, idx, 0));
    }
    
    sort(CardLength.begin(), CardLength.end(), greater<int>());
    
    answer = CardLength[0] * CardLength[1];
    
    return answer;
}