class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string ans;//答案
        stack<string> ch;//存字串到stack，然後反著壓出來到vector
        string temp;//暫存字串
        temp.clear();

        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if(c!=' '){
                do{
                    c = s[i];
                    if(c == ' ')//不這麼做會多執行一次導致存入的字串後面有空格
                        break;
                    temp.push_back(c);
                    i++;
                    
                }while(c!=' ' && s[i]!=NULL);
                i--;//把多跑的一個字元扣回來
                ch.push(temp);
                temp.clear();
            }
        }

        while(!ch.empty()){
            vs.push_back(ch.top());
            ch.pop();
        }
        
        for(int i = 0 ; i < vs.size() ; i++){
            ans += vs[i];//字串連接方法
            if(i != vs.size() - 1)
                ans.push_back(' ');//將字元放入字串的方法
        }

        return ans;
    }
};
