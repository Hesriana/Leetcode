class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int current = 1;

        for(int x:target){

            while(x > current){
                ans.push_back("Push");
                ans.push_back("Pop");
                current++;
            }
            
            ans.push_back("Push");
            current++;
        }

        return ans;
    }
};
/*class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int store[105] = {0};
        int flag = 0;

        for(int i = 1 ; i <= n ; i++){
            if(i == target[flag]){
                flag++;
                store[i]++;
                if(flag == target.size())
                    break;
            }
            else{
                store[i] += 2;
            }
        }

        for(int i = 0 ; i <= n ; i++){
            if(store[i] == 1)
                ans.push_back("Push");
            else if(store[i] == 2){
                ans.push_back("Push");
                ans.push_back("Pop");
            }  
        }

        return ans;
    }
};*/
