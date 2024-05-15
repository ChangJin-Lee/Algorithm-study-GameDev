#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Lifeboat
{
    private:
    vector<int> people;
    int limit;
    int answer = 0;
    
    public: 
    Lifeboat(vector<int>people, int limit)
    {        
        this->people = people;
        this->limit = limit;
        sort(this->people.begin(), this->people.end());
    }

    int calculateBoat();
};

int Lifeboat::calculateBoat()
{
    int head = 0;
    int tail = people.size() - 1;
    
    while(head <= tail)
    {
        if(people[head] + people[tail] <= limit)
        {
            head++;
            tail--;
        }
        else
        {
            tail--;
        }
        
        answer++;
    }
    return answer;
}


int solution(vector<int> people, int limit) {
    
    Lifeboat myLifeboat(people, limit);
    
    return myLifeboat.calculateBoat();
}