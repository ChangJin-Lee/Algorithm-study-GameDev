#include <iostream>
#include <algorithm>
#include <vector>

#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

void updateMap(int i, int w);
int dfs(int k);
void query(int i);
void propagate(int node, int start, int end);
void update(int node, int start, int end, int left, int right, int diff);
long long query(int node, int start, int end, int idx);

// tuple 1.부모 2.자식
vector<int> v[100001];
// 노드 번호를 나타내는 벡터
// vector<int> mapping;
int leftSide[100001];
int rightSide[100001];
int idx = 0;
int output = 0;

long long tree[400001]; // 세그먼트 트리
long long  lazy[400001]; // Lazy propagation에 사용되는 배열

int main()
{
    fastcpp;
    int n, m, input, w;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> input;
        if(input != -1)
        {
            v[input].push_back(i);
        }
    }

    dfs(1);

    for(int i = 0; i < m; i++)
    {
        cin >> input;

        switch (input)
        {
        case 1:
            cin >> input >> w;
            update(1,1,n,leftSide[input],rightSide[input],w);
            break;
        case 2:
            cin >> input;
            output = 0;
            cout << query(1,1,n,leftSide[input]) << "\n";
            break;
        default:
            break;
        }
    }

}

int dfs(int k)
{
    leftSide[k] = ++idx;
    rightSide[k] = idx;
    
    for(auto l : v[k])
    {
        rightSide[k] = max(rightSide[k], dfs(l));
    }

    return rightSide[k];
}

// Lazy propagation을 적용하는 함수
void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start < end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// 구간을 변경하는 함수
void update(int node, int start, int end, int left, int right, int diff) {
    propagate(node, start, end);
    if (left <= start && end <= right) {
        lazy[node] += diff;
        propagate(node, start, end);
    } else if (!(end < left || right < start)) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right, diff);
        update(node * 2 + 1, mid + 1, end, left, right, diff);
    }
}

// 노드를 탐색하는 함수
long long query(int node, int start, int end, int idx) {
    propagate(node, start, end);
    if (start == end) {
        return tree[node];
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            return query(node * 2, start, mid, idx);
        } else {
            return query(node * 2 + 1, mid + 1, end, idx);
        }
    }
}