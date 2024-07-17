class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        int sum,left = 0,right = nums.size() - 1,ans = 0;
        //left從左邊收過來，right則是右邊，sum計算兩邊和，ans算有幾組sum == k
        sort(nums.begin(),nums.end());//要先排序才能用
        
        while(left < right){
            
            sum = nums[left] + nums[right];

            if(sum < k)
                left++;
            else if(sum > k)
                right--;
            else{
                ans++;
                left++;
                right--;
            }
        }

        return ans;
    }
};
