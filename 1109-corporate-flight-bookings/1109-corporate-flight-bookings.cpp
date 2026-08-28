class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> prefix(n,0);
        for(auto & b : bookings){
            prefix[b[0] -1] += b[2];
            if(b[1] != n){
                prefix[b[1]] -= b[2];
            }
        }

        for(int i = 1; i<n; i++){
            prefix[i] += prefix[i-1];
        }
        return prefix;
        
    }
};