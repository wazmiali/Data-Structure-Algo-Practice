#include <stdlib.h>
#include <stdio.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // Sort the array to use two pointers
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];  // Initial closest sum

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            // If the sum is closer to the target, update the closest sum
            if (abs(sum - target) < abs(closestSum - target)) {
                closestSum = sum;
            }

            // Move pointers based on the sum
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                // If sum equals the target, we've found the closest possible sum
                return sum;
            }
        }
    }

    return closestSum;
}