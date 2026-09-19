//用stack，把遞增的長方形位置記下來
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        
        for(int i = 0 ; i < heights.size() ; i++){

            if(st.empty() || heights[st.top()] < heights[i]){
                st.push(i);
            }
            else{
                int temp = st.top();
                st.pop();

                res = max(res,heights[temp] * (st.empty() ? i : i - st.top() - 1));//如果stack空了，那就算從現在到這個地方的總面積
                i--;
            }
        }

        return res;
    }
};
