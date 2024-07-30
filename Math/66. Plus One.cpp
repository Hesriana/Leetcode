class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry= 1;

        for(int i = digits.size() - 1 ; i >=0 ; i--){
            if(digits[i] + carry == 10){
                digits[i] = 0;
            }
            else{
                digits[i] += 1;
                carry = 0;
                break;
            }
        }

        if(carry == 1){
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }

        return digits;
    }
};
/*what i write
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        stack<int> s,s2;
        vector<int> ans;
        int carry = 0;

        for(int i = 0 ; i < digits.size() ; i++)
            s.push(digits[i]);
        
        s.top() = s.top() + 1;

        while(!s.empty()){

            s.top() += carry;
            
            if(s.top() == 10){
                carry = 1;
                s2.push(0);
                s.pop();
            }
            else{
                carry = 0;
                s2.push(s.top());
                s.pop();
            }
        }

        if(carry == 1)
            s2.push(1);
        
        while(!s2.empty()){
            ans.push_back(s2.top());
            s2.pop();
        }

        return ans;
    }
};
*/
