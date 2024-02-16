#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

void FindNCA(vector<pair<int, vector<int>>> &tree, int A,int B);

int main()
{
    fastcpp;
    int T, N;
    int A, B;

    cin >> T;

    while(T--)
    {
        cin >> N;
        vector<pair<int, vector<int>>> tree(N+1, {-1,{}});

        for(int i = 0; i < N-1; i++)
        {
            cin >> A >> B;
            tree[A].second.push_back(B);
            tree[B].first = A;
        }

        cin >> A >> B;

        FindNCA(tree, A,B);
    }
}

void FindNCA(vector<pair<int, vector<int>>> &tree, int A,int B)
{
    vector<int> aV;
    int nA = A; 
    int nB = B;

    while(nA != -1)
    {
        aV.push_back(nA);
        nA = tree[nA].first;
    }

    while(nB != -1)
    {
        if(find(aV.begin(), aV.end(), nB) != aV.end())
        {
            cout << nB << "\n";
            break;
        }
        else
        {
            nB = tree[nB].first;
        }
    }
}