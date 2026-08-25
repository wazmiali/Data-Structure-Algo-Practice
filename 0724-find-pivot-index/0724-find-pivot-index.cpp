class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int lsum=0,rsum=0;
        int total_sum=0;
        for(int i=0; i<n; i++){
            total_sum+=nums[i];
        }

        int sec=0;
        for(int i=0;i<n;i++){
            rsum=total_sum-nums[i]-lsum;
            if(rsum == lsum){
                return i;
            }
            lsum+=nums[i];
        }
        return -1;
        
    }
};