#include <iostream>
#include <math.h>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int DAQ(int e, int r, int c);

int main()
{
    fastcpp;
    int n,r,c;

    cin >> n >> r >> c;
    
    cout << DAQ(n,r,c);
}

int DAQ(int e, int r, int c)
{
    int length = pow(2,e-1);
    int partition = pow(4,e-1);

    if(e == 1)
    {
        if(r == 0 && c == 0)
            return 0;
        else if(r == 0 && c == 1)
            return 1;
        else if(r == 1 && c == 0)
            return 2;
        else if(r == 1 && c == 1)
            return 3;
    }
    
    if(r < length)
    {
        if(c < length)
            return DAQ(e-1,r,c);
        else
            return partition + DAQ(e-1, r, c-length);
    }
    else
    {
        if(c < length)
            return 2*partition + DAQ(e-1, r-length, c);
        else
            return 3*partition + DAQ(e-1, r-length, c-length);
    }
}