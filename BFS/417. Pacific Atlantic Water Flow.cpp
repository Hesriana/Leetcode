//先從島的每一邊把水流進來，最後看哪邊是兩片海都能留到的
class Solution {
public:

    void dfs(int x,int y,vector<vector<int>> ocean){

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans; 
        int dir[5] = {1,0,-1,0,1};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        
        //很新奇的寫法，可以在function裡面，再塞function
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int r,int c,vector<vector<bool>>& ocean){
            ocean[r][c] = true;
            for(int i = 0 ; i < 4 ; i++){
                
                int dr = r + dir[i];
                int dc = c + dir[i+1];

                if(dr >= 0 && dr < m && dc >= 0 && dc < n && !ocean[dr][dc] && heights[r][c] <= heights[dr][dc]){
                    dfs(dr,dc,ocean);
                }
            }
        };

        for(int i = 0 ; i < m ; i++){
            dfs(i,0,pacific);
            dfs(i,n-1,atlantic);
        }

        for(int i = 0 ; i < n ; i++){
            dfs(0,i,pacific);
            dfs(m-1,i,atlantic);
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
