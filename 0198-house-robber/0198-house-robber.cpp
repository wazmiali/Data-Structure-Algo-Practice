// house-robber
// Using DP
class Solution {
public:
    int solve(vector<int>& nums, int size, int index, vector<int>& dp) {
        if (index >= size) return 0;

        if (dp[index] != -1) return dp[index];

        int option1 = nums[index] + solve(nums, size, index + 2, dp);
        int option2 = solve(nums, size, index + 1, dp);

        return dp[index] = max(option1, option2);
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1);
        return solve(nums, size, 0, dp);
    }
};
