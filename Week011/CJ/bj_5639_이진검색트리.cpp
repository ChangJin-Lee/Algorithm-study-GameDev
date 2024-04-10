#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* LeftNode;
    Node* RightNode;
};

class Gpraph
{
    public:
        Node* rNode;
        int inputInt;


    void PrefixOrder(Node* node)
    {
        if(node->value > inputInt)
        {
            if(node->LeftNode)
                PrefixOrder(node->LeftNode);
            else
            {
                Node* newNode = new Node();
                newNode->value = inputInt;
                node->LeftNode = newNode;
            }
        }
        else if (node->value < inputInt)
        {
            if(node->RightNode)
                PrefixOrder(node->RightNode);
            else
            {
                Node* newNode = new Node();
                newNode->value = inputInt;
                node->RightNode = newNode;
            }
        }
    }

    void PrintPostfixOrder(Node* node)
    {
        if(node->LeftNode)
            PrintPostfixOrder(node->LeftNode);
        if(node->RightNode)
            PrintPostfixOrder(node->RightNode);
        cout << node->value << "\n";
    }
};

int main()
{
    Gpraph graph;
    Node* rnode = new Node();
    int input;

    cin >> input;
    rnode->value = input;

    while(cin >> input)
    {
        graph.inputInt = input;
        graph.PrefixOrder(rnode);
    }

    graph.PrintPostfixOrder(rnode);
}