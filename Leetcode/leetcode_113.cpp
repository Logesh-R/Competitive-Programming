//113. Path Sum II

class Solution {
    int expectedSum = 0;
    vector<vector<int>> retu;
    void walkThrough(TreeNode* root, vector<int> ret, int count){        
        ret.push_back(root->val);
        if(root->left == NULL && root->right == NULL && count + root->val == expectedSum){
            retu.push_back(ret); return;
        }
        
        if(root->left != NULL) walkThrough(root->left, ret, count + root->val);
        if(root->right != NULL) walkThrough(root->right, ret, count + root->val);
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        expectedSum = sum;
        vector<int> ret;
        if(root == NULL) return retu;
        walkThrough(root, ret, 0);
        return retu;
    }
};