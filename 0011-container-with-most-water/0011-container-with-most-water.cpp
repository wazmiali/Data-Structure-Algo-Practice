class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            water=max(water,min(height[i],height[j])*abs(i-j));
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return water;
    }
};