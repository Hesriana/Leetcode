//2024/08/08
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        int big = rows*cols;
        int change = 1,chx = 1,chy = 1; 
        int x = cStart,y = rStart;
        vector<vector<int>> ans;
        vector<int> a = {rStart,cStart};
        ans.push_back(a);
        while(1){

            if(ans.size() == big)
                break;

            for(int i = 0 ; i < change ; i++){
                vector<int> temp;
                x = x + chx;
                if(x >=0 && y >=0){
                    if(x + 1 <= cols && y + 1 <= rows){
                        temp.push_back(y);
                        temp.push_back(x);
                        ans.push_back(temp);
                    }
                }
            }

            for(int i = 0 ; i < change ; i++){
                vector<int> temp;
                y = y + chy;
                if(x >=0 && y >=0){
                    if(x + 1 <= cols && y + 1 <= rows){
                        temp.push_back(y);
                        temp.push_back(x);
                        ans.push_back(temp);
                    }
                }
            }

            change++;
            chx = chx*-1;
            chy = chy*-1;
        }

        return ans;
    }
};
