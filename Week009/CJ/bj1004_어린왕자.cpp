#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool isTargetDistance(int x, int y, int r)
{
    return !(x <= r && y <= r) && (x <= r || y <= r);
}

int calculateDistance(int x0, int y0, int cx, int cy) 
{
    return pow(x0 - cx, 2) + pow(y0 - cy, 2);
}


int main()
{
    int T, n;           // TC, planetary system count
    int x0, y0, x1, y1; // Starting point, End point
    int cx, cy, r;      // circle axis, radius

    cin >> T;

    while (T--)
    {
        int answer = 0;
        cin >> x0 >> y0 >> x1 >> y1;
        cin >> n;
        while (n--)
        {
            cin >> cx >> cy >> r;
            int distance1 = calculateDistance(x0,y0,cx,cy);
            int distance2 = calculateDistance(x1,y1,cx,cy);
            int powR = pow(r, 2);
            if (isTargetDistance(distance1, distance2, powR))
            {
                answer++;
            }
        }
        cout << answer << endl;
    }
}