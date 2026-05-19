class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int res = 0;
        int area = 0;
        
        queue<pair<int,int>> q;
        int d[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    bool flag = false;
                    area = 1;
                    q.push(make_pair(i,j));

                    while(!q.empty()){
                        
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int k = 0 ; k < 4 ; k++){
                            
                            int x = r + d[k][0];
                            int y = c + d[k][1];

                            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                                flag = true;
                                area++;
                                grid[x][y] = 0;
                                q.push(make_pair(x,y));
                            }
                        }
                    }
                    area = flag ? area -1 : area;
                    res = res < area ? area : res;                    
                }
            }
        }

        return res; 
    }
};
