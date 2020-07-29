//1207. Unique Number of Occurrences

class Solution {
public:

    // HashTable using static array
    bool uniqueOccurrences(vector<int>& arr) {
        
        //hashTable to store frequency of each num in arr
        //freqTable to count frequency redundancy from hashTable
        //MaxSize is 2002, as -1000 <= arr[i] <= 1000

        int hashTable[2002] = {0,}, freqTable[2002] = {0,};
        
        for(int a: arr)
            hashTable[a+1000]++;  
        
        for(int i=0; i<2002; ++i){
            if(hashTable[i] == 0)
                continue;
            
            if(freqTable[hashTable[i]]++ == 1)
                return false;
        }
            
        return true;
    }

    // Alternate unordered_map STL approach 
    bool uniqueOccurrences_unordered_map_approach(vector<int>& arr) {
        
        unordered_map<int, int> hashTable, freqTable;
        
        for(int a: arr)
            hashTable[a+1000]++;
        
        for(unordered_map<int, int>::iterator it=hashTable.begin(); it!=hashTable.end(); ++it){
            if(freqTable[it->second]++ == 1)
                return false;
        }
            
        return true;
    }
};