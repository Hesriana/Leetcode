class Solution {
public:
    bool isHappy(int n) {
        
        int check[100000] = {0};
        int sum = 0;

        while(n != 1){
            sum = 0;
            while(n != 0){
                int temp = n%10;
                sum += temp*temp;
                n = n/10;
            }
            n = sum;
            check[n]++;
            if(check[n] == 2)
                break;
        }

        if(n == 1)
            return true;
        else
            return false;
    }
};
/*
sample code

class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        else if(n<10) return false;
        else{
            int sum=0;
            while(n>0){
                int temp=n%10;
                sum+= temp*temp;
                n=n/10;
            }
            return isHappy(sum);
        }
    }
};*/
