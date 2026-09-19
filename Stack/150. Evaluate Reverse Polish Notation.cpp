class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop(); 
                int a = st.top(); st.pop(); 

                int result;
                if(token == "+") result = a + b;
                else if(token == "-") result = a - b;
                else if(token == "*") result = a * b;
                else result = a / b; 

                st.push(result);
            } else {
                st.push(stoi(token));//文字轉成數字 stoi(num)
                cout << stoi(token) << endl;
            }
        }

        return st.top();
    }
};

/*class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int a,b;
        stack<int> st;

        for(string s:tokens){
            
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                char ch = s[0];
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                switch(ch){
                    case '+':
                        st.push(a + b);
                        break;
                    case '-':
                        st.push(a - b);
                        break;
                    case '*':
                        st.push(a * b);
                        break;
                    case '/':
                        st.push(a / b);
                        break;
                }
                
            }
            else{
                
                int temp = 0;
                int base = 1;
                for(int i = s.size() - 1 ; i >= 0 ; i--){
                    int t = s[i] - '0';
                    if(t <= 9 && t >= 0){
                        temp += base*t;
                        base *= 10;
                    }
                }
                if(s[0] == '-'){
                    temp = temp*-1;
                }
                cout << temp << endl;
                st.push(temp);
            }
        }

        return st.top();
    }
};*/
