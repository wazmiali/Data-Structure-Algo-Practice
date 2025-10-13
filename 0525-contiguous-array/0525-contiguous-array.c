#include <stdlib.h>

#define MAX_SIZE 200005  // Since nums.length <= 1e5, prefix sums can range from -n to +n

int findMaxLength(int* nums, int numsSize) {
    int* map = (int*)malloc(sizeof(int) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        map[i] = -2;  // Initialize to a special value (-2)
    }

    int maxLength = 0;
    int sum = 0;
    map[numsSize] = -1;  // Shifted index for sum = 0

    for (int i = 0; i < numsSize; i++) {
        sum += (nums[i] == 0) ? -1 : 1;

        int index = sum + numsSize;  // Shift to handle negative indices

        if (map[index] >= -1) {
            maxLength = (i - map[index] > maxLength) ? (i - map[index]) : maxLength;
        } else {
            map[index] = i;
        }
    }

    free(map);
    return maxLength;
}