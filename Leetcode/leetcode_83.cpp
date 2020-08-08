//83. Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr)
            return head;
        
        ListNode* temp = head;
        while(temp->next != nullptr){
            if(temp->next->val == temp->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        
        return head;
    }
};