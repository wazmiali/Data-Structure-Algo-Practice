class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>v;
        vector<int>temp;

        sort(nums.begin(), nums.end());
        magic(nums,v,temp,n,0);
        return v;

    }

        void magic(vector<int>&nums, vector<vector<int>>&v, vector<int>& temp, int n, int index){

            v.push_back(temp);
            for(int i = index; i<n; i++){

                if(i == index || nums[i] != nums[i-1])
                {
                    temp.push_back(nums[i]);
                    magic(nums, v, temp, n, i+1);
                    temp.pop_back();
                }

            }
        }
    
};