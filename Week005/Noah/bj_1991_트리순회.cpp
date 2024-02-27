#include <iostream>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

vector<char> lc(30);
vector<char> rc(30);

void preorder(int cur);
void inorder(int cur);
void postorder(int cur);

int main(){
    fastcpp;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        char c, l, r;
        cin >> c >> l >> r;
        if(l != '.'){
            lc[c - 'A' + 1] = l - 'A' + 1;
        }
        if(r != '.'){
            rc[c - 'A' + 1] = r - 'A' + 1;
        }
    }
    
    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);

    return 0;
}

void preorder(int cur){
    // subtree의 root 출력
    cout << char(cur + 'A' - 1);
    // left child가 존재한다면
    if(lc[cur] != 0){
        // left child가 root인 subtree를 호출
        preorder(lc[cur]);
    }
    if(rc[cur] != 0){
        preorder(rc[cur]);
    }
}

void inorder(int cur){
    if(lc[cur] != 0){
        inorder(lc[cur]);
    }
    cout << char(cur + 'A' - 1);
    if(rc[cur] != 0){
        inorder(rc[cur]);
    }
}

void postorder(int cur){
    if(lc[cur] != 0){
        postorder(lc[cur]);
    }
    if(rc[cur] != 0){
        postorder(rc[cur]);
    }
    cout << char(cur + 'A' - 1);
}