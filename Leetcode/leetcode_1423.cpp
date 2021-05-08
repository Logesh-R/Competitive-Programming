class Solution {
public:    
    int maxScore(vector<int>& cardPoints, int k) {
        
        int maxCardScore = 0, kCardSum = 0;
        
        for(int i=0; i<k; i++)
            kCardSum += cardPoints[i];
        
        maxCardScore = kCardSum;
        
        for(int i=1; i<=k; i++){
            kCardSum += (cardPoints[cardPoints.size()-i] - cardPoints[k-i]);
            if(kCardSum > maxCardScore)
                maxCardScore = kCardSum;
        }
        
        return maxCardScore;
    }
};