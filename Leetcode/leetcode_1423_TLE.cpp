class Solution {
    int maxCardScore;
public:
    void findMaxScore(vector<int> &cardPoints, int start, int end, int currScore, int noOfCardsPicked, int k) {
        
        if(noOfCardsPicked == k){
            if(maxCardScore < currScore)
                maxCardScore = currScore;
            
            return;
        }
        
        findMaxScore(cardPoints, start+1, end, currScore + cardPoints[start], noOfCardsPicked+1, k);
        findMaxScore(cardPoints, start, end-1, currScore + cardPoints[end], noOfCardsPicked+1, k);
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        
        if(k > cardPoints.size())
            return 0;
        
        maxCardScore = 0;
        findMaxScore(cardPoints, 0, cardPoints.size()-1, 0, 0, k);
        
        return maxCardScore;
    }
};