Array Partitions
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Step 2: Sum up every first element of the pairs
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }

    return sum;
}
