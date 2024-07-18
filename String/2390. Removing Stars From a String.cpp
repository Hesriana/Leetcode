class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st,temp;
        string ans;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]!='*')
                st.push(s[i]);
            else
                st.pop();
        }

        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }

        return ans;
    }
};
