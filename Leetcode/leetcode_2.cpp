//2. Add Two Numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head = nullptr, *tail = nullptr, *temp;
        int carry = 0;

        //Iterating until both LL are null
        while(l1 != nullptr || l2 != nullptr){
            
            if(l1 != nullptr){
                carry += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != nullptr){
                carry += l2->val;
                l2 = l2->next;
            }
            
            temp = new ListNode(carry%10);
            carry = carry / 10;
            
            if(head == nullptr){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        
        //just to add extra carry, while is not required if is sufficient
        while(carry){
            temp = new ListNode(carry%10);
            carry = carry / 10;
            
            if(head == nullptr){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        
        return head;
    }
};