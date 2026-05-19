class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int res = 0;
        queue<pair<int,int>> q;
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    
                    grid[i][j] = -2;
                    q.push(make_pair(i,j));

                    while(!q.empty()){

                        int r = q.front().first;
                        int c = q.front().second;

                        q.pop();
                        cout << r << " " << c << endl;
                        for(int k = 0 ; k < 4 ; k++){
                            int x = r + d[k][0];
                            int y = c + d[k][1];
                            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()){
                                if(grid[x][y] == 1){
                                    grid[x][y] = -2;
                                    q.push(make_pair(x,y));
                                }
                                else if(grid[x][y] != -2){
                                    res++;
                                }
                            }
                            else{
                                res++;
                            }
                        }
                        cout << res << endl;
                    }

                    break; 
                }
            }
        }

        return res;
    }
};
