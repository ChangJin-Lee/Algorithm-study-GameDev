#include <iostream>
#include <vector>
#include <string>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

bool HasIndex(vector<int> &v, int idx);
void GetPermutation(vector<string> &p, vector<string> &v, int idx, int k);
bool GetMagicalString(string &p, int k);

int main()
{
    fastcpp;
    int n = 0;
    int k = 0;
    int answer = 0;
    string input = "";
    vector<string> v;
    vector<string> p;
    
    cin >> n;
    
    for(int index = 0; index < n; index++)
    {
        cin >> input;
        v.push_back(input);
    }
    cin >> k;

    for(int index = 0; index < n; index++)
    {
        GetPermutation(p, v, index, k);
    }
    
    for(int index = 0; index < p.size(); index++)
    {
        if(GetMagicalString(p[index], k))
            answer++;
    }

    cout << answer;
}

bool HasIndex(vector<int> &v, int idx)
{
    for(int index = 0; index < v.size(); index++)
    {
        if(idx == v[index])
            return true;
    }
    return false;
}

void GetPermutation(vector<string> &p, vector<string> &v, int idx, int k)
{
    pair<int, vector<int>> front;
    vector<pair<int, vector<int>>> q;
    vector<int> tmp;
    string foo = "";
    
    q.push_back({0, {idx}});

    while(!q.empty())
    {
        front = q.front();
        q.erase(q.begin());
        
        if(front.first == v.size() - 1)
        {
            for(int index = 0; index < v.size(); index++)
            {
                foo += v[front.second[index]];
            }
            p.push_back(foo);
            foo = "";
        }

        for(int index = 0; index < v.size(); index++)
        {
            if(!HasIndex(front.second, index))
            {
                tmp = front.second;
                tmp.push_back(index);
                q.push_back({front.first+1, tmp});
            }
        }
    }
}

bool GetMagicalString(string &p, int k)
{
    int count = -1;
    int size = p.size();
    int i = 0;
    vector<int> v(size, 0);
    string p2 = p+p;

    for(int index = 1; index < size; index++)
    {
        while(i > 0 && p[i] != p[index])
        {
            i = v[i-1];
        }

        if(p[i] == p[index])
        {
            i++;
            v[index] = i;
        }
    }


    i = 0;
    for(int index = 0; index < size*2; index++)
    {
        while( i > 0 && p[i] != p2[index])
        {
            i = v[i-1];
        }

        if(p[i] == p2[index])
        {
            i++;
            if(i == size)
            {
                count++;
                i = v[i-1];
            }
        }
    }

    return count == k;
}