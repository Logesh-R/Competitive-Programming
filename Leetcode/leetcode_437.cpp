//437. Path Sum III

class Solution {
        int expectedSum = 0, retu = 0;
        
        void walkThrough(TreeNode* root, vector<int> &temp){        
            
            for(int i=0; i<temp.size(); ++i){
                temp[i] += root->val;
                if(temp[i] == expectedSum) retu++;
            }
            if(root->val == expectedSum) retu++;
            temp.push_back(root->val);
        
            if(root->left != NULL) walkThrough(root->left, temp);
            if(root->right != NULL) walkThrough(root->right, temp);
        }
    public:
        int pathSum(TreeNode* root, int sum) {
            expectedSum = sum;
            if(root == NULL) return retu;
            
            vector<int> temp;
            walkThrough(root, temp);
            
            return retu;
        }
};