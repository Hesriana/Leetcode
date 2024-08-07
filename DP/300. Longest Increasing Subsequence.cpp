class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> LIS;//increasing sequence
        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++)
            LIS.push_back(1);
        
        for(int i = 1 ; i < nums.size() ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(nums[i] > nums[j] && LIS[i] < LIS[j] + 1){
                    LIS[i] = LIS[j] + 1; 
                }
            }
        }
        
        for(int i = 0 ; i < LIS.size() ; i++){
            if(ans < LIS[i])
                ans = LIS[i];
        }

        return ans;
    }
};
