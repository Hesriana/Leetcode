class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
        vector<int> ans,s;
        
        k = k % nums.size();

        for(int i = nums.size() - k ; i < nums.size() ; i++){
            s.push_back(nums[i]);
        }

        for(int i = 0 ; i < s.size() ; i++){
            ans.push_back(s[i]);
        }

        for(int i = 0 ; i < nums.size() - k ; i++){
            ans.push_back(nums[i]);
        }

        nums.clear();

        for(int i = 0 ; i < ans.size() ; i++){
            nums.push_back(ans[i]);
        }
    }
};
