class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0,sum = 0,temp = 0;
        int index = 0;
        for(int i = 0;i < height.size();i++){
            if(height[i] >= max){
                max = height[i];
                index = i;
                temp = 0;
            }else{
                temp += max - height[i];
            }
            sum += max -height[i];
        }
        if(index < height.size() - 1){
            max = 0;
            sum -= temp;
            for(int i = height.size()-1;i >= index;i--){
                if(height[i] >= max){
                    max = height[i];
                }else{
                    sum += max - height[i];
                }
            }
        }
        return sum;
    }
};