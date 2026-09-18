class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int mat_row_siz = matrix[0].size() - 1;
        int l = 0,r = matrix.size() - 1;
        int x;
        //cout << r << endl;
        while(r >= l){

            x = (l + r)/2;
            //cout << l << " " << x << " " << r << endl;
            if(matrix[x][0] <= target && matrix[x][mat_row_siz] >= target){
                break;
            }
            else if(matrix[x][0] > target){
                r = x - 1;
            }
            else{
                l = x + 1;
            }
        }
        //cout << x;
        l = 0;
        r = mat_row_siz;
        int res;
        while(r >= l){

            res = (r + l)/2;
            if(matrix[x][res] == target){
                return true;
            }
            else if(matrix[x][res] > target){
                r = res - 1;
            }
            else{
                l = res + 1;
            }
        }
        return false;
    }
};
