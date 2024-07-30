class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans = vector<int>(temperatures.size(),0);//預設全部為0
        stack<int> s;
        int i = 0;

        s.push(i++);

        while(!s.empty() && i < temperatures.size()){
            if(temperatures[s.top()] < temperatures[i]){//假如有溫度較高的天就進入迴圈找哪寫比自己溫度低
                while(!s.empty()){
                    if(temperatures[s.top()] < temperatures[i]){
                        ans[s.top()] = i - s.top();
                        s.pop();
                    }
                    else
                        break;
                }
                s.push(i++);
            }
            else{
                s.push(i++);
            }
        }

        return ans;
    }
};
