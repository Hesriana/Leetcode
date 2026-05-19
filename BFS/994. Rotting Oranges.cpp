class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int flash = 0;
        int ans = 0;
        bool flag = 0;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                    flag = true;
                }
                else if(grid[i][j] == 1){
                    flash++;
                }
            }
        }

        while(!q.empty()){

            int qlen = q.size();

            for(int j = 0 ; j < qlen ; j++){

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0 ; i < 4 ; i++){
                    
                    int x = r + d[i][0];
                    int y = c + d[i][1];

                    if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                        flash--;
                        grid[x][y] = 2;
                        q.push(make_pair(x,y));
                    }
                }
            }

            ans++;
        }
        
        ans = flag ? ans-1 : ans;
        return flash == 0 ? ans : -1;
    }
};
