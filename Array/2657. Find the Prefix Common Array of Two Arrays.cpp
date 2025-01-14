class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        vector<int> ans,record;
        int common = 0;

        for(int i = 0 ; i < A.size() ; i++)
            record.push_back(0);
        
        for(int i = 0 ; i < A.size() ; i++){
            record[A[i] - 1]++;
            record[B[i] - 1]++;
            if(record[A[i] - 1] == 2){
                record[A[i] - 1] = 0;
                common++;
            }
            if(record[B[i] - 1] == 2){
                record[B[i] - 1] = 0;
                common++;
            }
            ans.push_back(common);
        }

        return ans;
    }
};
