
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0; 
        
        for (int i = 0; i < 31; i++) {
            int rep = (1 << i); 
            int cnt = 0; 
            
            for (auto ele : nums) {
                if (rep & ele) {
                    
                    cnt++;
                }
            }
            if (cnt >= k) {
                ans = ans + rep;
            }
        }
        return ans;
    }
};