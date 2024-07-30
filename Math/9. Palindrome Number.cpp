class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
        
        int org = x;
        int rev = 0;

        while(x != 0){

            if(rev > INT_MAX/10)
                return false;//testcase30 會有overflow的機會
            //reverse的方法
            rev = rev*10 + x%10;
            x = x / 10;
        }

        return rev == org;
    }
};

/*what I write
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
        
        vector<int> v;

        while(x != 0){
            v.push_back(x%10);
            x = x/10;
        }

        vector<int> rv = v;
        reverse(v.begin(),v.end());

        if(rv == v)
            return true;
        else
            return false;
    }
};*/
