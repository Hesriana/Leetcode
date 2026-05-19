//先檢查四邊是不是有島嶼，有了話，全部改成@，之後再改回去O，O改成X
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        if(board.empty() || board[0].empty()) return;
        int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;

        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if(i != 0 && i != board.size() - 1 && j != 0 && j != board[i].size() - 1) continue;
                if(board[i][j] != 'O') continue;
                
                q.push(make_pair(i,j));
                board[i][j] = '@';

                while(!q.empty()){

                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++){
                        
                        int x = r + d[k][0];
                        int y = c + d[k][1];

                        if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == 'O'){
                            board[x][y] = '@';
                            q.push(make_pair(x,y));
                        }
                    }
                }
            }
        }

        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == '@'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }


    }
};
