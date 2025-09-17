// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// LeetCode 1416

class Solution {
public:
    bool equalPartition(int arr[], int N, int targetSum)
    {
        if (targetSum == 0)
            return true;

        if (N == 0)
            return false;

        if (arr[N - 1] > targetSum)
            return equalPartition(arr, N - 1, targetSum);

        return equalPartition(arr, N - 1, targetSum) ||
               equalPartition(arr, N - 1, targetSum - arr[N - 1]);
    }
    
    bool canPartition(vector<int>& nums)
    {
        int N = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0)
        {
            return false;
        }

        return equalPartition(nums.data(), N, totalSum / 2);
    }
};
