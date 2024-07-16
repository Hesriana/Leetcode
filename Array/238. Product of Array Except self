class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans,check;//紀錄為0的項
        int product = 1;//記錄整個nums的乘積
        

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0){
                product *= nums[i];
            }
            if(nums[i] == 0)
                check.push_back(i);
                
        }
        //有此項是否為0和nums裡0有幾個狀況排列組合成4種情況
        /*for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0 && check.size() == 1)
                ans.push_back(product);
            else if(nums[i] == 0 && check.size() >= 2)
                ans.push_back(0);
            else if(nums[i] != 0 && check.size() > 0)
                ans.push_back(0);
            else
                ans.push_back(product / nums[i]);
        }*/
        //有兩種情況都會是塞0，所以可改成下列寫法，少一個if判斷
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0 && check.size() == 1)
                ans.push_back(product);
            else if(nums[i] != 0 && check.size() == 0)
                ans.push_back(product / nums[i]);
            else
                ans.push_back(0);
        }

        return ans;
    }
};
