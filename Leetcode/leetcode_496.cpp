//496. Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, int> mappi;
        stack<int> stackie;
        vector<int> ret(nums1.size(), 0);
        
        for(int i=0; i<nums2.size();){
            //pushing to stack until next element is lesser
            while(i<nums2.size() && (stackie.empty() || nums2[i]<stackie.top())){
                stackie.push(nums2[i]); i++;
            }
            
            if(i<nums2.size()){
                //Storing hash value in mappi for each top less than current nums2[i]
                while(!stackie.empty() && stackie.top() < nums2[i]){
                    mappi[stackie.top()] = nums2[i];
                    stackie.pop();
                }
            }else{
                //At end; elements in stack doesnt have next max so assigning -1
                while(!stackie.empty()){
                    mappi[stackie.top()] = -1;
                    stackie.pop();
                }
            }
        }
        
        for(int i=0; i<nums1.size(); ++i){
            ret[i] = mappi[nums1[i]];
        }
        
        return ret;
    }
};