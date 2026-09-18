class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result = {-1,-1};
        int left = ans(nums,target,false);
        int right = ans(nums,target,true);

        result[0] = left;
        result[1] = right;

        return result;
    }

    int ans(vector<int>& nums,int target,bool foundBig){

        int left = 0;
        int right = nums.size() - 1;
        int res = -1;
        
        while(left <= right){

            int mid = (left + right)/2;

            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{

                res = mid;

                if(foundBig){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return res;
    }    

};
