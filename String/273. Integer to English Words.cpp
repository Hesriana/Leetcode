//難點在要確定甚麼時候要加空白甚麼時候不用加
class Solution {
public:
    string numberToWords(int num) {
        
        vector<string> data;
        string ans;

        if(num == 0)
            return "Zero";
        
        vector<int> nums;
        string n[] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string t[] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string s[] = {"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string bt[] = {"","Thousand","Million","Billion"};

        while(num > 0){
            nums.push_back(num%1000);
            num = num/1000;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            string temps = "";
            if(nums[i]/100 > 0){
                temps +=n[nums[i]/100];
                temps += " ";
                temps += "Hundred";
                if(i != 0 || nums[i]%100 != 0)
                    temps += " ";
            }
            nums[i] = nums[i]%100;
            if(nums[i] < 20 && nums[i] > 10){
                temps += s[nums[i] - 10 - 1];
                if(i != 0)
                    temps += " ";
            }
            else if(nums[i] != 0){
                temps += t[nums[i]/10];
                if(nums[i]/10 != 0 && nums[i]%10 != 0)
                    temps += " ";
                temps += n[nums[i]%10];
                if(i != 0)
                    temps += " ";
            }
            
            if(temps != ""){
                temps += bt[i];
                data.push_back(temps);
            }    
        }

        for(int i = data.size() - 1 ; i >= 0 ;i--){
            ans += data[i];
            if(i!=0)
                ans += " ";
        }
        
        return ans;
    }
};
