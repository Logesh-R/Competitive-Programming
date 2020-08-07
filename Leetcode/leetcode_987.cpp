//987. Vertical Order Traversal of a Binary Tree

class Solution {
    map<int, vector<int>> mappi;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        queue<int> value;
        int cnt, val;
        
        if(root == nullptr)
            return ret;
        
        que.push(root); value.push(0);

        //queue based iterative tree traversal
        while(que.size() != 0){
            map<int, vector<int>> mappi2;
            cnt = que.size();
            while(cnt--){
                val = value.front(); value.pop();
                TreeNode* temp = que.front(); que.pop();
                
                if(temp == nullptr) continue;
                
                mappi2[val].push_back(temp->val);
                que.push(temp->left); value.push(val-1);
                que.push(temp->right); value.push(val+1);
            }

            //sorting each level elements with same vertical position
            for(map<int, vector<int>>::iterator it = mappi2.begin(); it != mappi2.end(); it++){
                sort(it->second.begin(), it->second.end());
                mappi[it->first].insert(mappi[it->first].end(), it->second.begin(), it->second.end());
            }
        }
        
        for(map<int, vector<int>>::iterator it = mappi.begin(); it != mappi.end(); it++){
            ret.push_back(move(it->second));
        }
        
        return ret;
    }
};