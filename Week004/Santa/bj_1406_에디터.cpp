#include <iostream>
#include <string>

#define fastTime ios::sync_with_stdio(false), cin.tie(0);

using namespace std;

// node 
struct node
{
    char data;
    // address of node 
    node* nextNode = 0;
    node* prevNode = 0;
};

// linked list class 
class myLinkedList
{
    // private member variable
    private:
        node* head;
        node* cursor;
        node* headNode;

    // public member function declaration 
    public: 
        // constructor 
        myLinkedList()
        {
            head =  NULL;
            cursor = NULL;
            headNode = NULL;
        }

        // insert node 
        void insertNode(char n);

        // delete node 
        void deleteNode();

        void moveCursorLeft()
        {
            if(cursor->prevNode != NULL) 
            {
                cursor = cursor->prevNode;
            }
        }

        void moveCursorRight()
        {
            if(cursor->nextNode != NULL)
            {
                cursor = cursor->nextNode;
            }
        }

        // get head
        node* getHead()
        {
            return headNode;
        }

        node* getCursor()
        {
            return cursor;
        }

        // print linked list 
        void printNode(node* headNode);
};

// add back node
void myLinkedList::insertNode(char n)
{
    // make new node 
    node* newNode = new node;
    newNode->data = n;

    // if there is no data 
    if(headNode == NULL)
    {
        headNode = new node;
        headNode->data = '!';

        head = newNode;
        head->prevNode = headNode;
        headNode->nextNode = head;
        cursor = newNode;
    }
    else
    {
        // cursor is in the middle 
        if(cursor->nextNode != NULL)
        {
            newNode->nextNode = cursor->nextNode;
            newNode->prevNode = cursor;

            cursor->nextNode->prevNode = newNode;
            cursor->nextNode = newNode;
            cursor = newNode;   
        }
        // cursor is at the end 
        else
        {
            newNode->prevNode = cursor;
            cursor->nextNode = newNode;
            cursor = newNode;
        }
    }
}

// delete node 
void myLinkedList::deleteNode()
{
    if(cursor == headNode)
    {
        return;
    }

    node* deletedNode = cursor;
    cursor = deletedNode->prevNode;

    // cursor is in the middle 
    if(deletedNode->nextNode != NULL)
    {
        deletedNode->prevNode->nextNode = deletedNode->nextNode;
        deletedNode->nextNode->prevNode = deletedNode->prevNode;
    }
    // cursor is at the end 
    else
    {
        deletedNode->prevNode->nextNode = nullptr;
    }
    // delete node 
    delete deletedNode;
}

// print linked list 
void myLinkedList::printNode(node* headNode)
{
    if(headNode != NULL)
    {
        // print head node data 
        cout << headNode->data;
        // recurcive function print next node of current node
        printNode(headNode->nextNode);
    }
}


int main()
{
    fastTime;

    myLinkedList myLL;
    string input;
    int testCase = 0;
    char command, value = ' ';

    cin >> input; 

    for(int idx = 0; idx < input.length(); idx++)
    {
        myLL.insertNode(input[idx]);
    }

    cin >> testCase; 

    while(testCase--)
    {
        cin >> command;
        
        switch(command)
        {
            case 'L':   
                myLL.moveCursorLeft();
                break;

            case 'D':
                myLL.moveCursorRight();
                break;
            
            case 'B':
                myLL.deleteNode();
                break;
            
            case 'P': 
                cin >> value;
                myLL.insertNode(value);
                break;
        }
    }

    // print data 
    myLL.printNode(myLL.getHead()->nextNode);

    return 0;
}
