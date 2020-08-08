//61. Rotate List

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == nullptr)
            return head;
        
        vector<ListNode*> temp;
        
        ListNode* headTemp = head;
        while(headTemp != nullptr){
            temp.push_back(headTemp);
            headTemp = headTemp->next;
        }
        
        k %= temp.size();
        
        if(k != 0){
            temp[temp.size()-1]->next = head;
            temp[temp.size()-k-1]->next = nullptr;
            head = temp[temp.size()-k];
        }
        
        return head;
    }
};