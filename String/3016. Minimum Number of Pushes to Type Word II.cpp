class Solution {
public:
    int minimumPushes(string word) {
        
        int nums[26] = {0};
        vector<int> data;

        for(char c:word){
            nums[c - 'a']++;
        }

        sort(nums,nums + 26);

        for(int i = 0 ; i < 26 ; i++){
            if(nums[i] > 0)
                data.push_back(nums[i]);
        }

        int sum = 0;
        
        if(data.size() <= 8){
            for(int i = 0 ; i < data.size() ; i++){
                sum += data[i];
            }
        }
        else if(data.size() <= 16){
            for(int i = 0 ; i < data.size() ; i++){
                if(i < data.size() - 8){
                    sum += 2*data[i];
                }
                else{
                    sum += data[i];
                }
            }
        }
        else if(data.size() <= 24){
            for(int i = 0 ; i < data.size() ; i++){
                if(i < data.size() - 16){
                    sum += 3*data[i];
                }
                else if(i < data.size() - 8){
                    sum += 2*data[i];
                }
                else{
                    sum += data[i];
                }
            }
        }
        else{
            for(int i = 0 ; i < data.size() ; i++){
                if(i < data.size() - 24){
                    sum += 4*data[i];
                }
                else if(i < data.size() - 16){
                    sum += 3*data[i];
                }
                else if(i < data.size() - 8){
                    sum += 2*data[i];
                }
                else{
                    sum += data[i];
                }
            }
        }

        return sum;
    }
};
