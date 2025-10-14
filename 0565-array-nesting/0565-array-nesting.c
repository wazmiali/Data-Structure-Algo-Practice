int arrayNesting(int* nums, int numsSize) {
    int maxLen = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != -1) {  
            int start = i;
            int count = 0;

            while (nums[start] != -1) {
                int temp = nums[start];
                nums[start] = -1;  
                start = temp;
                count++;
            }

            if (count > maxLen)
                maxLen = count;
        }
    }

    return maxLen;
}
