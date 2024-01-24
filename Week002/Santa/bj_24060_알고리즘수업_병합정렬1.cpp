#include <iostream>
#include <vector>
#define fastTime ios::sync_withstdio(false), cin.tie(0)

using namespace std; 

vector <int> myArray; 
vector <int> tempArray;

int TargetNumber = 0;
int kTh = 0;
int result = -1;


void merge(int start, int mid, int end)
{
    int tempIndex = 0;
    int startPoint = start; 
    int midPoint = mid + 1;

    while(startPoint <= mid && midPoint <= end) 
    {
        myArray[startPoint] <= myArray[midPoint] ? 
        tempArray[tempIndex++] = myArray[startPoint++] :
        tempArray[tempIndex++] = myArray[midPoint++];
    }

    // left subarray is remained 
    while (startPoint <= mid)
    {
        tempArray[tempIndex++] = myArray[startPoint++];
    }

    while (midPoint <= end)
    {
        tempArray[tempIndex++] = myArray[midPoint++];
    }

    startPoint = start; 
    midPoint = mid + 1;
    tempIndex = 0;

    while(startPoint <= end)
    {
        myArray[startPoint++] = tempArray[tempIndex++];
        
        kTh += 1;

        if(kTh == TargetNumber)
        {
            result = myArray[startPoint - 1];
        }
    }
}


void mergeSort(int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}


int main()
{
    int idx = 0;
    int size = 0; 
    int arrayValue = 0;
    
    cin >> size >> TargetNumber;
    
    // Resize vectors to the specified size
    myArray.resize(size);
    tempArray.resize(size);

    while(idx < size)
    {
        cin >> arrayValue;
        myArray[idx++] = arrayValue;
    }

    mergeSort(0, myArray.size() - 1);

    cout << result;

    return 0;
}