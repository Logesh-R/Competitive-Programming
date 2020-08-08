//86. Partition List

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(head == nullptr) return head;
        
        ListNode *t1=head, *lhead=nullptr, *ghead=nullptr, *ltail=nullptr, *gtail=nullptr;
        
        while(t1 != nullptr){
            if(t1->val < x){
                if(lhead==nullptr){ 
                    lhead = t1; 
                    ltail = t1; 
                }
                else{ 
                    ltail->next = t1; 
                    ltail = t1;
                };
                
                t1 = t1->next;
                ltail->next = nullptr;
            }else{
                if(ghead==nullptr){ 
                    ghead = t1; 
                    gtail = t1; 
                }
                else{ 
                    gtail->next = t1; 
                    gtail = t1;
                };
                
                t1 = t1->next;
                gtail->next = nullptr;
            }
        }
        
        if(ltail == nullptr)
            lhead = ghead;
        else
            ltail->next = ghead;
        
        return lhead;
    }
};