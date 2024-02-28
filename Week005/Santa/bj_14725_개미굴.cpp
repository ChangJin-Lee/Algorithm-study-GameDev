#include <iostream> 
#include <string>
#include <vector>
#include <map>

using namespace std;

class TrieNode 
{
private:    
    map<string, TrieNode*> children; // key == 먹이, value == 다음 트라이 노드

public:
    void InsertNode(vector<string>& key, int index)
    {
        if(index == key.size())
        {
            return;
        }


        // if key is not in the children 
        if(children.find(key[index]) == children.end())
        {
            children[key[index]] = new TrieNode();
        }

        children[key[index]]->InsertNode(key, index + 1);
    }


    void PrintNode(int depth)
    {
        for(auto& child : children)
        {
            for(int idx = 0; idx < depth; idx++)
            {
                cout << "--"; 
            }
            cout << child.first << '\n';
            child.second->PrintNode(depth + 1);
        }
    }
};




int main()
{
    int n, k = 0;
    
    cin >> n;
    
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < n; i++)
    {
        cin >> k;

        vector<string> inputValues(k);

        for(int j = 0; j < k; j++)
        {
            cin >> inputValues[j];
        }
        
        root->InsertNode(inputValues, 0);
   }

   root->PrintNode(0);
   
   return 0;
}
