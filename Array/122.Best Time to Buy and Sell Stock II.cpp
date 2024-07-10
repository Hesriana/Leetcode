class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int buy = prices[0];
        int profit = 0;

        for(int i = 1 ; i < prices.size() ; i++){
            if(prices[i - 1] >= prices[i]){
                buy = prices[i];
                sum += profit;
                profit = 0;
            }
            else if(prices[i] < buy){
                buy = prices[i];
                sum += profit;
                profit = 0;
            }
            else if(profit < prices[i] - buy){
                profit = prices[i] - buy;
                if(i == prices.size() - 1){
                    sum += profit;
                }
            }
            
        }

        return sum;
    }
};
