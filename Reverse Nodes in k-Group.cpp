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
    class Solution 
{
public:
        
     /*
Node* reverse(Node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* temp = NULL;
    Node* prev = NULL;
    int count = 0;
  
   //1 2 3 4-->1    4 3 2
    while (current != NULL && count < k) {
       temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }
  
   
    if (temp != NULL)
        head->next = reverse(temp, k);
  
   
    return prev;
}*/


    
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        
        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        auto node=head;
        for (int i=0; i < k; ++i)
        {
            if ( ! node  )
                return head; // nothing to do list too sort
            node = node->next;
        }

        auto new_head = reverse( head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
        
      
    }
};
