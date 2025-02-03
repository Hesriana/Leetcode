class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        string str,ans = "";
        int time;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                int base = 1;
                time = 0;
                str = "";
                
                while(1){
                    if(st.top() == '['){
                        st.pop();
                        reverse(str.begin(),str.end());
                        break;
                    }
                    str.push_back(st.top());
                    st.pop();
                }

                while(1){
                    if(st.empty())
                        break;
                    int temp = st.top() - '0';
                    if(temp < 0 || temp > 9){
                        break;
                    }
                    time += base*temp;
                    base = base*10;
                    st.pop();
                }

                for(int j = 0 ; j < time ; j++){
                    for(char c:str){
                        st.push(c);
                    }
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
