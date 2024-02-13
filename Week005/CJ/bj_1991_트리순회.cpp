#include <iostream>
#include <tuple>
#include <map>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

void PreOrder(tuple<char, char, char> bNode);
void InOrder(tuple<char, char, char> bNode);
void PostOrder(tuple<char, char, char> bNode);

map<char,tuple<char, char, char>> myNode;

int main()
{
    int n;
    char a, b, c;

    cin >> n;

    while(n--)
    {
        cin >> a >> b >> c;
        myNode[a] = {a, b, c};
    }   
    PreOrder(myNode['A']);
    cout << "\n";
    InOrder(myNode['A']);
    cout << "\n";
    PostOrder(myNode['A']);
}

void PreOrder(tuple<char, char,char> bNode)
{
    cout << get<0>(bNode);
    if(get<1>(bNode) != '.')
        PreOrder(myNode[get<1>(bNode)]);
    if(get<2>(bNode) != '.')
        PreOrder(myNode[get<2>(bNode)]);
}

void InOrder(tuple<char, char,char> bNode)
{
    if(get<1>(bNode) != '.')
        InOrder(myNode[get<1>(bNode)]);
    cout << get<0>(bNode);
    if(get<2>(bNode) != '.')
        InOrder(myNode[get<2>(bNode)]);
}

void PostOrder(tuple<char, char,char> bNode)
{
    if(get<1>(bNode) != '.')
        PostOrder(myNode[get<1>(bNode)]);
    if(get<2>(bNode) != '.')
        PostOrder(myNode[get<2>(bNode)]);
    cout << get<0>(bNode);
}