class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        vector<int> ans;
        unordered_map<int,int> ball,color;//ball是存球當前的顏色 color是當前使用過的顏色        
        int distinct = 0;
        for(auto &q : queries) {
            
            int pos = q[0], c = q[1];
            
            if(ball.count(pos))
                if(--color[ball[pos]] == 0) distinct--;
            
            ball[pos] = c;
            
            if(++color[c] == 1) distinct++;
            ans.push_back(distinct);

        }
        
        return ans;
    }
};
