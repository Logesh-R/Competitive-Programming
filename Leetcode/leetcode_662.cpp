class Solution {
    map<int, unsigned long long int> leftMin, rightMax;
public:
    void findWidthOfBinaryTree(TreeNode* root, unsigned long long int count, int level){
        if(root == NULL)
            return;
        if(leftMin.find(level) == leftMin.end() || leftMin[level] > count)
            leftMin[level] = count;
        if(rightMax.find(level) == rightMax.end() || rightMax[level] < count)
            rightMax[level] = count;
        
        findWidthOfBinaryTree(root->left, 2*count, level+1);
        findWidthOfBinaryTree(root->right, (2*count) + 1, level+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        
        unsigned long long int maxWidth = 0, currWidth;
        findWidthOfBinaryTree(root, 1, 1);
        
        for(auto val: leftMin){
            currWidth = rightMax[val.first] - leftMin[val.first] + 1;
            if(currWidth > maxWidth)
                maxWidth = currWidth;
        }
            
        return maxWidth;
    }
};