//103. Binary Tree Zigzag Level Order Traversal

class Solution {
    bool zigzag = true;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> que;
        vector<vector<int>> ret;
        
        if(root == NULL)
            return ret;
        
        que.push(root);
        
        while(que.size()){
            int cnt = que.size();
            vector<int> vect;
            for(int i=0; i<cnt; ++i){
                TreeNode* temp = que.front();
                que.pop();
                vect.push_back(temp->val);
                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
            }
            //Just reverse the vector on even levels
            if(!zigzag) reverse(vect.begin(), vect.end());
            zigzag = !zigzag;
            ret.push_back(move(vect));
        }
        
        return ret;
    }
};