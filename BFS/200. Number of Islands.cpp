class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        queue<pair<int,int>> q;
        
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = 0 ; i < grid.size() ; i++){
            
            for(int j = 0 ; j < grid[0].size() ; j++){
                
                if(grid[i][j] == '1'){

                    ans++;
                    q.push(make_pair(i,j));
                    
                    while(!q.empty()){

                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int i = 0 ; i < 4 ; i++){
                            
                            int x = r + d[i][0];
                            int y = c + d[i][1];

                            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == '1'){
                                grid[x][y] = '0';
                                q.push(make_pair(x,y));
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
