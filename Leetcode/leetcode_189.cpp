//189. Rotate Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> ret;
        k %= nums.size();
        if(k==0) return;
        
        k = nums.size()-k;
        
        ret.insert(ret.end(), nums.begin()+k, nums.end());
        ret.insert(ret.end(), nums.begin(), nums.begin()+k);
        
        nums = move(ret);
    }
};