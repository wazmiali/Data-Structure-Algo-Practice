class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        for(int i=1; i<n; i++){
            int lmax = height[i];
            for(int j=0; j<i; j++)
                lmax = max (lmax, height[j]);

                int rmax = height[i];
                for(int j=i+1; j<n; j++)

                rmax = max(rmax, height[j]);
                res = res+(min(lmax, rmax)- height[i]);
            
        }
        
    return res;
    }
};