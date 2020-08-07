//19. Remove Nth Node From End of List

class Solution {
    int curr = 0, tot = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return head;
        
        tot++;
        if(head->next == nullptr){ 
            curr++;   
            //check when head is Nth Node
            if(tot == n && curr == n)
                head = head->next;
            return head; 
        }
        
        removeNthFromEnd(head->next, n);
        
        if(curr++ == n){
            if(head->next != nullptr)
                head->next = head->next->next;
        }
        
        //check when head is Nth Node
        if(tot == n && curr == n)
            head = head->next;
        return head;
    }
};