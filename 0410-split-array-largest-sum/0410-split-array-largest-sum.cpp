class Solution {
public:

    bool check(vector<int>& nums, int k, int mid){

        int count = 1;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] >mid) return false;
            if(sum+nums[i] <=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        if(nums.size()<k) return -1;
        int low = 0;
        int high = 0;
        int ans = -1;
        for(int i=0; i<nums.size(); i++){

            low=max(low, nums[i]);
            high+=nums[i];
        }

        while(low<=high)
        {
            int mid=high - (high - low)/2;
            if(check(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};