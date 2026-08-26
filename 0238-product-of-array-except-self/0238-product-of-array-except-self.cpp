class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;

        for(int num : nums){
            if(num == 0){
                ++zeroCount;
            }
            else{
                product *= num;
            }
        }

        for(int& num : nums){
            if(zeroCount > 1){
                num = 0;
            }
            else if (zeroCount == 1){
                num = (num == 0) ? product : 0;
            }
            else{
                num = product / num;
            }
        }

        return nums;
        
    }
};