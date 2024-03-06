#include <iostream>
#include <algorithm>

int dim[500][500];

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastcpp;
    
    int n, temp;
    cin >> n;

    for(int d = 0; d < n; d++){
        for(int w = 0; w < d+1; w++){
            cin >> temp;
            dim[d][w] = temp;
        }
    }

    for(int d = n-1; d > 0; d--){
        for(int w = 0; w < d; w++){
            dim[d-1][w] += max(dim[d][w], dim[d][w+1]);
        }
    }

    cout << dim[0][0];

    return 0;
}