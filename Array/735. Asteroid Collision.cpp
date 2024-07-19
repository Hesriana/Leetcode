class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> s;
        vector<int> ans;
        s.push(asteroids[0]);//s.empty()的判斷後這句可以寫入for迴圈
        
        for(int i = 1 ; i < asteroids.size() ; i++){

            if(s.empty())
                s.push(asteroids[i]);
            //如果第一項是負的，那第二項是正的了話，這兩項不會相撞，正的像又跑，負的向左跑
            else if(asteroids[i]*s.top() > 0 || asteroids[i] > 0){//所以方向相同(相乘大於0)或是方向不同，但他是向右走的都可以存入stack
                cout << asteroids[i] << endl;
                s.push(asteroids[i]);
            }
            else{
                while(!s.empty()){
                    if(asteroids[i]*s.top() > 0){//確認隕石方向是否不同
                        s.push(asteroids[i]);
                        break;
                    }
                    else if(abs(asteroids[i]) < abs(s.top())){//撞到比自己大的那就結束
                        break;
                    }
                    else if(abs(asteroids[i]) > abs(s.top())){
                        s.pop();
                        if(s.empty()){//當這顆隕石大於stack的所有隕石並且撞碎他們後，要把這顆存入stack裡面
                            s.push(asteroids[i]);
                            break;
                        }
                    }
                    else if(abs(asteroids[i]) == abs(s.top())){//撞到一樣大的，所以還要s.pop()
                            s.pop();
                            break;
                    }
                }

            }
        }

        while(!s.empty()){
            ans.push_back(s.top());//存入ans
            s.pop();
        }

        reverse(ans.begin(),ans.end());//因為用stack存，資料會相反

        return ans;
    }
};
