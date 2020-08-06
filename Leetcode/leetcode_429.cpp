//429. N-ary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        list<Node*> que;
        vector<vector<int>> ret;
        
        if(root == NULL)
            return ret;
        
        que.push_back(root);
        
        while(que.size()){
            int cnt = que.size();
            vector<int> vect;
            for(int i=0; i<cnt; ++i){
                Node* temp = que.front();
                que.pop_front();
                if(temp == NULL) continue;
                vect.push_back(temp->val);
                que.insert(que.end(), temp->children.begin(), temp->children.end());
            }
            ret.push_back(move(vect));
        }
        
        return ret;
    }
};