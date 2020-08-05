//111. Minimum Depth of Binary Tree

class Solution {
    int minn = INT_MAX;
    void walkThrought(TreeNode* root, int count){
        if(root->left==NULL && root->right==NULL){
            if(minn > count) minn = count;
            return;
        }
        
        if(root->left!=NULL)
            walkThrought(root->left, count+1);
        
        if(root->right!=NULL)
            walkThrought(root->right, count+1);
    }
public:
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        walkThrought(root, 0);
        
        return minn+1;
    }
};