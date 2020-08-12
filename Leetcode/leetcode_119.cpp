//119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> ret;
        for(int i=0; i<=row; ++i){
            ret.push_back(1);
            for(int j=ret.size()-2; j>0; --j)
                ret[j] += ret[j-1];
        }
        return ret;
    }
};