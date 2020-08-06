//442. Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mappi;
        vector<int> ret;
        
        for(int i=0; i<nums.size(); ++i){
            mappi[nums[i]]++;
            if(mappi[nums[i]] > 1)
                ret.push_back(nums[i]);
        }
        
        return ret;
    }
};