class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int currentSum = 0;
        int result = INT_MAX;

        int n = nums.size();

        while(r < n ){
            currentSum += nums[r];
            while(currentSum >= target){
                result = min(result, r - l + 1);

                currentSum -= nums[l];
                l++;
            }
            r++;
        }

        return result == INT_MAX ? 0 : result;
    }
};