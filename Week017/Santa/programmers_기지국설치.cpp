#include <iostream>
#include <vector>
using namespace std;


class StationInstaller
{
    private: 
    int answer = 0;
    
    public: 
    void installStations(int n, vector<int> stations, int w);
    int getAnswer(){ return answer; };
};


void StationInstaller::installStations(int n, vector<int> stations, int w)
{    
    // 기지국 설치된 위치 인덱스
    int i = 0;
    
    for(int idx = 1; idx <= n; ++idx)
    {
        // 기지국 전파 범위안에 있는지?  기지국 설치 위치 인덱스가 범위 안인지? 
        if(idx <= stations[i] + w && idx >= stations[i] - w && i < stations.size())
        {
            // 전파 최대 범위로 이동
            idx = stations[i] + w;
            i++;
        } 
        else
        {
            answer++;
            idx += w * 2;
        }      
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    StationInstaller myStation;
    
    myStation.installStations(n, stations, w);
    answer = myStation.getAnswer();
    
    return answer;
}