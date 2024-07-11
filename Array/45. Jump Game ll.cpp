class Solution {
public:
    int jump(vector<int>& nums) {
        
        int temp = 0;
        int jump = 0;

        if(nums.size() - 1 <= 0)    
            return 0;
        
        for(int i = 1 ; i < nums.size() ; i++){
            nums[i] = max(nums[i - 1] , nums[i] + i);//找出每一項能跳到最遠的地方，nums[i-1]代表他能比這項跳得更遠，nums[i]+i代表這項能跳的最遠距離
        }

        while(temp < nums.size() - 1){
            jump++;
            temp = nums[temp];//遍歷一遍
        }

        return jump;
    }
};
