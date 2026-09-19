class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> ans(n,0);
        stack<int> st;
        int idx,time = 0,pretime = 0;
        char type[10];

        for(string log:logs){

            sscanf(log.c_str(),"%d:%[^:]:%d", &idx,&type,&time);//sscanf這種用法第一次看到，需要再去看看他的規則

            if(type[0] == 's'){
                if(!st.empty())
                    ans[st.top()] += time - pretime;
                st.push(idx);
            }
            else{
                ans[st.top()] += ++time - pretime;
                st.pop();
            }

            pretime = time;
        }

        return ans;
    }
};
