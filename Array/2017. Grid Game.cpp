class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        long long up = accumulate(begin(grid[0]),end(grid[0]),0LL),down = 0;
        long long ans = LONG_LONG_MAX;
        //up 是第一行的總和 down是第二行的總和

        //利用窮舉把所有機器人走的路線都跑一次
        for(int i = 0 ; i < grid[0].size() ; i++){
            up -= grid[0][i];//走上的方法
            ans = min(ans,max(up,down));//
            down += grid[1][i];//走下面方法
        }

        return ans;
    }
};
