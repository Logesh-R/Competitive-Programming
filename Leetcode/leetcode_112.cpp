//112. Path Sum

class Solution {
    bool sumExist = false;
    int expectedSum = 0;
    
    void walkThrough(TreeNode* root, int count){
        if(sumExist)return;
        
        if(root->left == NULL && root->right == NULL && count + root->val == expectedSum){
            sumExist = true; return;
        }
        
        if(root->left != NULL) walkThrough(root->left, count + root->val);
        if(root->right != NULL) walkThrough(root->right, count + root->val);
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        
        expectedSum = sum;
        walkThrough(root, 0);
        
        return sumExist;
    }
};