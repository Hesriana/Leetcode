class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int w1[26],w2[26];

        for(char c:word1){
            int temp = c - 'a';
            w1[temp]++;
        }

        for(char c:word2){
            int temp = c - 'a';
            w2[temp]++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(w1[i] != 0 && w2[i] == 0)
                return false;
            else if(w1[i] == 0 && w2[i] != 0)
                return false;
        }

        sort(w1,w1+26);
        sort(w2,w2+26);

        for(int i = 0 ; i < 26 ; i++){
            if(w1[i] != w2[i])
                return false;
        }

        return true;
    }
};
