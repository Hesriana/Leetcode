class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>> q;
        int startcolor = image[sr][sc];
        if(startcolor == color){
            return image;
        }
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        q.push(make_pair(sr,sc));
        image[sr][sc] = color;

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int x = r + d[i][0];
                int y = c + d[i][1];
                if(x >= 0 && y >= 0 && x < image.size() && y < image[0].size() && image[x][y] == startcolor){
                    image[x][y] = color;
                    q.push(make_pair(x,y));
                }
            }
        }

        return image;
    }
};
