class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0,right = nums.size() - 1;
        int res;

        while(left < right){

            res = left + (right - left) / 2;

            if(nums[res] > nums[right]){
                left = res + 1;
            }
            else{
                right = res;
            }

        }

        return nums[left];
    }
};
