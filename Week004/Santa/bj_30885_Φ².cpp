#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

struct node
{
    int idx; 
    long long size; 
    long long nextIdx;
    long long prevIdx;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    vector<node> myList (500001);
    deque<int> myDeque;
    const long long maxValue = LLONG_MAX;

    long long microbeIdx, tempSize, tempPrevSize, tempNextSize, tempIdx = 0;
    long long tempNextIdx, tempPrevIdx = 0;
    long long totalSize = 0;

    cin >> microbeIdx;

    for(int idx = 1; idx <= microbeIdx; idx++)
    {
        cin >> tempSize;

        totalSize += tempSize;

        myDeque.push_back(idx);

        myList[idx].idx = idx;
        myList[idx].size = tempSize;
        myList[idx].prevIdx = tempPrevIdx;
        myList[idx].nextIdx = tempNextIdx;

        myList[tempPrevIdx].nextIdx = idx;

        tempPrevIdx = idx;
    }
    
    // connect head to tail 
    myList[tempPrevIdx].nextIdx = 0;
    myList[0].size = maxValue;

    while(myDeque.size() != 1)
    {
        long long sum = 0;

        microbeIdx = myDeque.front();
        myDeque.pop_front();

        tempIdx = myList[microbeIdx].idx;
        tempSize = myList[microbeIdx].size;
        tempNextIdx = myList[microbeIdx].nextIdx;
        tempPrevIdx = myList[microbeIdx].prevIdx;

        tempPrevSize = myList[tempPrevIdx].size;
        tempNextSize = myList[tempNextIdx].size;

        if(tempPrevSize <= tempSize)
        {
            sum += tempPrevSize;
            myDeque.pop_back();
            
            myList[myList[tempPrevIdx].prevIdx].nextIdx = microbeIdx;
            myList[microbeIdx].prevIdx = myList[tempPrevIdx].prevIdx;

            myList[microbeIdx].size = tempSize + sum;
        }
        if(tempNextSize <= tempSize)
        {
            sum += tempNextSize;

            myDeque.pop_front();

            myList[tempPrevIdx].nextIdx = microbeIdx;
            myList[myList[tempNextIdx].nextIdx].prevIdx = microbeIdx;
            myList[microbeIdx].nextIdx = myList[tempNextIdx].nextIdx;

            myList[microbeIdx].size = tempSize + sum;
        }

        myDeque.push_back(microbeIdx); 
        }

    cout << myList[myDeque.front()].size << '\n';
    cout << myDeque.front();

    return 0;
}