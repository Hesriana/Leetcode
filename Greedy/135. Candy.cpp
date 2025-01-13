class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int i = 1;
        int candy = n;

        while(i < n){
            
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int flashback = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                flashback++;
                candy += flashback;
                i++;
            } 

            if(i == n)
                return candy;
            
            int order = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                order++;
                candy += order;
                i++;
            }

            candy -= min(order,flashback);
        }

        return candy; 
    }
};
