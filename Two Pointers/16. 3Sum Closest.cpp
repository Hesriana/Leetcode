class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int res;
        bool fir = 1;

        for(int i = 0 ; i < n ; i++){

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while(j < k){

                int total = nums[i] + nums[j] + nums[k];
                
                if(fir){
                    fir = 0;
                    res = total;
                }

                if(abs(res - target) >= abs(total - target)){
                    res = total;
                }

                if(total < target){
                    j++;
                }
                else if(total > target){
                    k--;
                }
                else{

                    return total;
                }
            }
        }

        return res;
    }
};
