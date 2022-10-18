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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int count = 0;
        
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        
        curr = head;
        
        count = count / 2;
        
        while(count--) curr = curr->next;
        
        return curr;
    }
};