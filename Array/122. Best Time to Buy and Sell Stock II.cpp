class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int buy = prices[0];
        int profit = 0;

        for(int i = 1 ; i < prices.size() ; i++){
            if(prices[i - 1] >= prices[i]){//當前一項已經比現在大或一樣時，代表可以現在賣掉
                buy = prices[i];//更新買入點
                sum += profit;//賣掉
                profit = 0;
            }
            else if(prices[i] < buy){//當出現能更低買入時，就可以更新買入點
                buy = prices[i];
                sum += profit;
                profit = 0;
            }
            else if(profit < prices[i] - buy){//如果發現能賣更多時，就更改profit
                profit = prices[i] - buy;
                if(i == prices.size() - 1){
                    sum += profit;
                }
            }
            
        }

        return sum;
    }
};
