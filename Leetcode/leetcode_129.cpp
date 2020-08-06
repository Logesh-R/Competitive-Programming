//129. Sum Root to Leaf Numbers

class Solution {
    int ret = 0;
    void walkThrough(TreeNode* root, int count){ 
        
        if(root == NULL) return;
        
        count = count*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            ret += count; return;
        }
        
        walkThrough(root->left, count);
        walkThrough(root->right, count);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        
        walkThrough(root, 0);
        return ret;
    }
};