#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> myMap;

long long FindEmptyRoom(long long room)
{
    if(myMap[room] == 0) 
    {
        return room;
    }

    return myMap[room] = FindEmptyRoom(myMap[room]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
        
    for(long long room : room_number)
    {   
        if(myMap[room] == 0)
        {
            answer.push_back(room);
            myMap[room] = room + 1;
        }
        else
        {
            long long emptyRoom = FindEmptyRoom(room);
            
            answer.push_back(emptyRoom);
            myMap[emptyRoom] = emptyRoom + 1;
        }
    }

    return answer;
}