class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int condidate, count = 0;

        for(int i=0; i<n; i++){
            if(count == 0){

                count = 1;

            condidate = nums[i];
            }
        else{
            if(condidate == nums[i])
                count++;

            else
                count--;
        }
        }
        return condidate;
        
    }
};