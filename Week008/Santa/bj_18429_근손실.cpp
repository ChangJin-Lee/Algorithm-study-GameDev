#include <iostream>
#include <vector>

using namespace std;


int muscle = 500;
int n, k, numCount; 

vector<pair<int, bool> > kit;


void protein(int idx)
{
    if(idx == n)
    {
        numCount++;
        return;
    }

    for(int i = 0; i < kit.size(); i++)
    {
        // 이미 확인한 숫자라면 다음으로
        if(kit[i].second) continue;

        // 근육양이 500보다 작아진다면 다음으로
        if(muscle + kit[i].first - k < 500) continue;

        muscle += kit[i].first - k; 
        kit[i].second = true;
        protein(idx + 1);
        muscle -= kit[i].first - k; 
        kit[i].second = false;
    }
}


int main()
{
    cin >> n >> k;

    for(int idx = 0; idx < n; idx++)
    {
        int num;
        cin >> num;

        kit.push_back(make_pair(num, false)); 
    }

    protein(0);

    cout << numCount;

    return 0;
}