//520. Detect Capital

#include <locale>

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool startupper = false;
        int lower = 0;
        
        if(word[0] >= 'A' && word[0] <= 'Z')
            startupper = true;
        
        for(int i=1; i<word.length(); ++i){
            if(word[i] >= 'a' && word[i] <= 'z')
                lower++;
        }

        if((lower==0 && startupper==true) || (lower==(word.length()-1)))
            return true;
        
        return false;
    }
};