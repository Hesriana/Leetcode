class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int sum = nums[0],m = 0;

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(nums[i] < nums[i+1]){
                sum += nums[i+1];
            }
            else{
                m = max(m,sum);
                sum = nums[i+1];
            }
        }
        
        m = max(m,sum);

        return m;
    }
};
