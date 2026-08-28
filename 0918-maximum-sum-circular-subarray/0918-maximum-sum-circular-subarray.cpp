class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best = nums[0];
        int bestmax = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];
        int result = nums[0];
        int sum = nums[0];

        for(int i = 1; i<nums.size(); i++){
            sum += nums[i];
            bestmax = max(bestmax + nums[i], nums[i]);
            maxsum = max(maxsum, bestmax);
            best = min(best + nums[i], nums[i]);
            minsum = min(minsum, best);
        }

        if(maxsum < 0){
            return maxsum;
        }
        return max(maxsum, sum-minsum);
        
    }
};