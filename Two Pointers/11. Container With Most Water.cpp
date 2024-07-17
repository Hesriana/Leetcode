class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximum = 0,left = 0,right = height.size() - 1,area;
        //left從左邊收過來，right則是右邊，area計算面積，maximum紀錄最大的area
        while(left < right){
            //算面積
            if(height[left] < height[right])
                area = height[left]*(right - left);
            else
                area = height[right]*(right - left);
            //紀錄最大值
            if(maximum < area)
                maximum = area;
            
            if(height[left] < height[right])
                left++;//左邊比較小時，左邊的pointer往右收一格
            else if(height[left] > height[right])
                right--;//右邊較小時。右邊的pointer往左收一格
            else{
                //若兩者數值相同，right往左收一格，left往右收一格
                right--;
                left++;
            }
        }

        return maximum;
    }
};
