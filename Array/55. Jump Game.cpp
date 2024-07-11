class Solution {
public:
    bool canJump(vector<int>& nums) {

        //goal是指要跳到的地方，從最後一項開始檢查跳不跳的到，假如跳的到就更新goal到能跳到原本goal的點

        int goal = nums.size() - 1;

        for(int i = nums.size() - 2 ; i >= 0 ; i--){
            
            int distance = goal - i;
            if(distance <= nums[i]){
                goal = i;
            }
        }

        if(goal == 0)//如果能走到第一項，那代表能從第一項跳到最後一項，回傳true
            return true;
        else
            return false;
    }
};
