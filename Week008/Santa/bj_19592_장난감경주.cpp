#include <iostream>
#include <algorithm>

#define fastLapTime 1000000

using namespace std; 


int testCase, players;
double boosterLimit, track, speed;

int check(int boosterLimit, double fastestTime, int mySpeed)
{
    double start = 1;
    double end = boosterLimit; 
    int mid = 0;

    if(track / speed < fastestTime)
    {
        return 0;
    }
    else if((track - boosterLimit) / mySpeed + 1 >= fastestTime)
    {
        return -1;
    }

    while(start <= end)
    {
        mid = (start + end) / 2;    

        if((track - mid) / mySpeed + 1 < fastestTime)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    } 

    return (int)start;
}

int main()
{
    cin >> testCase;

    while(testCase--)
    {
        cin >> players >> track >> boosterLimit;
        
        double fastestLapTime = fastLapTime;

        for(int idx = 1; idx < players; idx++)
        {
            cin >> speed;
        
            double lapTime = track / speed;

            fastestLapTime = lapTime < fastestLapTime ? lapTime : fastestLapTime;
        }

        cin >> speed;

        cout << check(boosterLimit, fastestLapTime, speed) << '\n';
    }

    return 0;
}