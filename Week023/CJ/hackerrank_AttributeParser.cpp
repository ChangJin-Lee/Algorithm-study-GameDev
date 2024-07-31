#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Node 
{
    string Name;
    map<string, string> Value;
    Node* ParentNode;
    vector<Node*> ChildNode;
};

class Html
{
    public:
        Node* rnode;
        string inputStr = "";
        
        Html()
        {
            rnode = new Node();
            rnode->ParentNode = NULL;
        }
        
        
        // html parsing

        string GetHtmlTag(string s)
        {
            string t = "";
            for(auto ch : s)
            {
                if (ch == ' ')
                {
                    break;
                }
                if(ch != '<' && ch != '>')
                {
                    t += ch;
                }
            }
            return t;
        }
        
        void SetHtmlJson(Node* node, string input)
        {
            int start = 0;
            int end = input.size()-1;
            int tagValueCnt = 0;
            string tagType = "";
            string tagValue = "";
            bool checkSign = false;
            
            while(input[start] != ' ')
            {
                start++;
            }
            
            for(int i = start + 1; i <= end; i++)
            {
                char cur = input[i];
                
                if ( cur == '=')
                {
                    checkSign = true;
                }
                
                if(cur != ' ' && cur != '\"' && cur != '=')
                {
                    if(!checkSign)
                        tagType+=cur;
                    else
                        tagValue+=cur;
                }
                else if ( cur == '\"')
                {
                    tagValueCnt++;
                    if(tagValueCnt >= 2)
                    {
                        node->Value[tagType] = tagValue;
                        tagType = "";
                        tagValue = "";
                        tagValueCnt = 0;
                        checkSign = false;
                    }
                }
            }
        }
        
        void ReadHtml(vector<string> inputs)
        {
            for(auto input : inputs)
            {
                // tag1, m[value] = "value";
                string tag = GetHtmlTag(input);
                
            }
        }
        
        void MakeTree(vector<string> inputs)
        {
            Node* cur = rnode;
            for(auto s : inputs)
            {
                // cout << s << "\n";
                if(s[1] == '/')
                {
                    cur = cur->ParentNode;
                    // cout << "enter / \n";
                }
                else
                {
                    // cout << "enter else \n";
                    Node* newNode = new Node();
                    newNode->ParentNode = cur;
                    // update newNode value
                    newNode->Name = GetHtmlTag(s);
                    // cout << "newNode->Name : " << newNode->Name << "\n";
                    SetHtmlJson(newNode, s);
                    cur->ChildNode.push_back(newNode);
                    cur = newNode;
                }
            }
        }
        
        
        // query parsing
        
        vector<string> GetInheritanceRelation(string s)
        {
            vector<string> treeMap;
            string st = "";
            for(auto cur : s)
            {
                if(cur == '.' || cur == '~')
                {
                    treeMap.push_back(st);
                    st = "";
                }
                else
                {
                    st += cur;
                }
            }
            treeMap.push_back(st);
            return treeMap;
        }
        
        void FindValueInTree(vector<string> ss)
        {
            for(auto s : ss)
            {
                vector<string> tags;
                // cout << "s : " << s << "\n";
                tags = GetInheritanceRelation(s);
                
                Node* cur = rnode;
                bool NotExist = false;
                
                // cout << "tag.back() : " << tags.back() << "\n";
                
                for(auto tag : tags)
                {
                    bool IsMoved = false;
                    // cout << "tag : " << tag << "\n";
                    if(tag == tags.back())
                        break;
                    for(auto nodes : cur->ChildNode)
                    {
                        if(nodes->Name == tag)
                        {
                            // cout << "name : " << nodes->Name << "\n";
                            // for(auto k : nodes->Value)
                            // {
                                // cout << k.first << " ... " << k.second << "\n";
                            // }
                            cur = nodes;
                            IsMoved = true;
                            break;
                        }
                    }
                    if(!IsMoved)
                    {
                        NotExist = true;
                        break;
                    }
                        
                }
                
                // cout << "notexist" << NotExist << "\n";
                
                if(NotExist)
                    cout << "Not Found!";
                else
                {
                    if(cur->Value.find(tags.back()) == cur->Value.end())
                    {
                        cout << "Not Found!";
                    }
                    else
                    {
                        cout << cur->Value[tags.back()];
                    }
                }
                    
                    
                cout << "\n";
            }
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    vector<string> inputs;
    vector<string> querys;
    Html html;
    
    cin >> n >> q;
    inputs.assign(n, "");
    querys.assign(q, "");
    
    cin.ignore();
    
    for(int i = 0; i < n; i++)
    {
        getline(cin, inputs[i]);
    }
    
    for(int i = 0; i < q; i++)
    {
        getline(cin, querys[i]);
    }
    
    html.MakeTree(inputs);
    
    html.FindValueInTree(querys);
      
    return 0;
}
