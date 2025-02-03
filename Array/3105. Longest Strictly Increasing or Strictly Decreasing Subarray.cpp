class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int dec = 0,inc = 0;
        int dcount = 0,icount = 0;

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(nums[i] < nums[i+1]){
                dcount++;
                
                inc = max(icount + 1,inc);
                icount = 0;
            }
            else if(nums[i] > nums[i+1]){
                icount++;

                dec = max(dcount + 1,dec);
                dcount = 0;
            }
            else{
                dec = max(dcount + 1,dec);
                inc = max(icount + 1,inc);
                dcount = 0;
                icount = 0;
            }
        }

        if(dcount != 0 || icount != 0){
            dec = max(dcount + 1,dec);
            inc = max(icount + 1,inc);
        }

        int ans = max(inc,dec);
        if(ans == 0)
            ans++;

        return ans;
    }
};
