class Solution {
public:
    int compress(vector<char>& chars) {

        vector<char> temp;
        stack<char> s;
        char c = chars[0];
        int num = 1;

        if (chars.size() == 1)
            return 1;

        for (int i = 0; i < chars.size() - 1; i++) {
            if (c == chars[i + 1]) {
                num++;
            } else {

                temp.push_back(c);
                c = chars[i + 1];
                if (num > 1) {
                    while (num != 0) {
                        s.push('0' + num % 10);
                        num = num / 10;
                    }
                    num = 1;
                    while (!s.empty()) {
                        temp.push_back(s.top());
                        s.pop();
                    }
                }
            }
        }

        temp.push_back(c);
        if (num > 1) {
            while (num != 0) {
                s.push('0' + num % 10);
                num = num / 10;
            }
            while (!s.empty()) {
                temp.push_back(s.top());
                s.pop();
            }
        }

        chars = temp;

        return chars.size();
    }
};
