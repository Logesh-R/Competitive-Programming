//98. Validate Binary Search Tree

class Solution {
public:
    vector<int> ret;
    void walkThroughTree(TreeNode* root){
        if(root == NULL)
            return;
        if(root->left!=NULL){
            walkThroughTree(root->left);
        }
        
        ret.push_back(root->val);
        
        if(root->right!=NULL){
            walkThroughTree(root->right);
        }
    }

    bool isValidBST(TreeNode* root) {
        
        walkThroughTree(root);
       
        for(int i=1; i<ret.size(); i++){
            if(ret[i-1] >= ret[i]) return false;
        }
        
        return true;
    }
};