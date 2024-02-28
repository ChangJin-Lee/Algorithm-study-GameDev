#include <iostream>
#include <vector> 

using namespace std;

struct treeNode
{
   char left;
   char right;
};

vector<treeNode> myTree(26);

// root - legt - right
void preOrder(char node)
{
    if(node == '.')
    { 
        return; 
    }

    cout << node;
    preOrder(myTree[node].left);
    preOrder(myTree[node].right);
}

// left - root - right
void inOrder(char node)
{ 
    if(node == '.')
    { 
        return; 
    }

    inOrder(myTree[node].left);
    cout << node;
    inOrder(myTree[node].right);

}

// left - right - root
void postOrder(char node)
{
  if(node == '.')
    { 
        return; 
    }

    postOrder(myTree[node].left);
    postOrder(myTree[node].right);
    cout << node;
}


int main()
{
    int n;
    cin >> n;

    for(int idx = 0; idx < n; idx++)
    {
        char root, left, right;
        cin >> root >> left >> right; 
        myTree[root].left = left;
        myTree[root].right = right;       
    }    

    preOrder('A');
    cout << '\n';
    inOrder('A');
    cout << '\n';
    postOrder('A');

    return 0;
}