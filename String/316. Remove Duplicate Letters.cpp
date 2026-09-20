class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string res;
        stack<char> st;
        vector<int> hash(30);
        bool visit[30] = {0};
        
        for(char c:s)
            hash[c - 'a']++;

        for(char c:s){

            if(!visit[c - 'a']){
                if(!st.empty()){
                    while(!st.empty() && c < st.top()){
                        if(hash[st.top() - 'a'] > 0){
                            visit[st.top() - 'a'] = false;
                            st.pop();
                        }
                        else{
                            break;
                        }
                    }
                }

                st.push(c);
                visit[c - 'a'] = true;
            }

            hash[c - 'a']--;
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
