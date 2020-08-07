//24. Swap Nodes in Pairs

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        queue<ListNode*> que1, que2;
        bool flag = true;
        while(head != nullptr){
            if(flag)
                que1.push(head);
            else
                que2.push(head);
            
            head = head->next;
            flag = !flag;
        }
        
        ListNode* rhead = nullptr, *rtail = nullptr, *temp;
        
        while(que2.size() || que1.size()){
            if(que2.size()){
                temp = que2.front(); que2.pop();
                temp->next = nullptr;
                if(rhead == nullptr){
                    rhead = temp; rtail = temp;
                }else{
                    rtail->next = temp; rtail = temp;
                }                    
            }
            
            if(que1.size()){
                temp = que1.front(); que1.pop();
                temp->next = nullptr;
                if(rhead == nullptr){
                    rhead = temp; rtail = temp;
                }else{
                    rtail->next = temp; rtail = temp;
                }                    
            }
        }
        
        return rhead;
    }
};