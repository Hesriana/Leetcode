class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];//min
        int ans = 0;

        for(int i = 0 ; i < prices.size() ; i++){
            if(mi > prices[i]){
                mi = prices[i];//find min 
            }
            else if(ans < prices[i] - mi)//if there are greater profile update ans
                ans = prices[i] - mi;
        }
        
        return ans;
    }
};
