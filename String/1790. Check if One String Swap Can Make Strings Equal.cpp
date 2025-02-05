class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int sw = 0,swp[2];

        if(s1.size() != s2.size())
            return false;
        
        int j = 0;
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] != s2[i]){
                sw++;
                if(j < 2){
                    swp[j] = i;
                    j++;
                }
            }
        }

        if(sw != 2 && sw != 0)
            return false;

        if(s1[swp[0]] != s2[swp[1]] || s1[swp[1]] != s2[swp[0]])
            return false;
        
        return true;
    }
};
