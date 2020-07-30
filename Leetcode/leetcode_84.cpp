//84. Largest Rectangle in Histogram

//Explaination - https://youtu.be/ZmnqCZp9bBs

#include <algorithm>
using namespace std;

class Solution {
    stack<int> stackie;
    int maxArea, currentArea, i, k, top, n;
public:
    Solution(){
        //to speedup the runtime
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    
    int largestRectangleArea(vector<int>& heights) {
        maxArea = 0; n = heights.size();
        
        //if histogram is already sorted
        if(is_sorted(heights.begin(), heights.end())){
            for (i = 0, k = n; i < n; i++)
                maxArea = max(maxArea, heights[i] * k--);
            
            return maxArea;
        }
        
        for(i=0; i<n; ++i){
            if(stackie.size()==0){
                stackie.push(i);
                continue;
            }
            
            while(stackie.size() > 0 && heights[stackie.top()] > heights[i]){
                top = stackie.top();
                stackie.pop();
                if(stackie.size() != 0)
                    currentArea = heights[top] * (i - stackie.top() -1);
                else
                    currentArea = heights[top] * i;
                
                maxArea = max(currentArea, maxArea);
            }
            
            stackie.push(i);
        }
        
        while(stackie.size() > 0){
            top = stackie.top();
            stackie.pop();
            if(stackie.size() != 0)
                currentArea = heights[top] * (i - stackie.top() -1);
            else
                 currentArea = heights[top] * i;
            
            maxArea = max(currentArea, maxArea);
        }
        
        return maxArea;
    }
};