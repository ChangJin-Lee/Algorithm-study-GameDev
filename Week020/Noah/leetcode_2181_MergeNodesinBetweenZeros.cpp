/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode *ans = head->next;
        ListNode *nextNode = ans;
        
        while(nextNode != nullptr){
            int sum = 0;
            
            while(nextNode->val != 0){
                sum += nextNode->val;
                nextNode = nextNode->next;
            }
            
            ans->val = sum;
            nextNode = nextNode->next;
            ans->next = nextNode;
            ans = ans->next;
        }
        
        return head->next;
    }
};