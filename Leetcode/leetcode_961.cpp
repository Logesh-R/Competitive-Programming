//961. N-Repeated Element in Size 2N Array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        
        //hashCounter array to keep count of each element frequency
        //when frequency count == n, return that number
        int hashCounter[10000] = {0,}, n = A.size()/2;
        for(int a: A)
        {
            if(++hashCounter[a]==n)
                return a;
        }
        
        return -1;
    }
};