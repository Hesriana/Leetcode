#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int max,min,sum = m + n - 2,j = 1;
        long long out = 1;

        if(m > n){
            max = m;
            min = n - 1;
        }
        else{
            max = n;
            min = m - 1;
        }    
        
        for(int i = max ; i <= sum ; i++){
            out *= i;
            if(j <= min){
                out = out/j;
                j++;
            }
        }
        return (int)out;
    }
};

int main(){

    int x,y,ans;
    Solution fun;
    
    cin >> x >> y;

    ans = fun.uniquePaths(x,y);

    cout << ans << endl;
    return 0;
}