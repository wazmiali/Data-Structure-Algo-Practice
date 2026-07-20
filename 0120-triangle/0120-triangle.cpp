class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = m;

        vector<int> prev(n, 1e9);
        prev[0] = triangle[0][0];

        for( int i = 1; i<m; i++){
            vector<int> temp(n, 1e9);

            for(int j = 0; j <= i; j++){
                int up = 1e9;
                int diag = 1e9;

                if( j < i) up = prev [j] + triangle[i][j];
                if(j > 0) diag = prev[j-1] + triangle[i][j];

                temp[j] = min(up, diag);
            }
            prev = temp;

        }

        int minC = INT_MAX;
        for(int j = 0; j < n; j++){
            minC = min(minC, prev[j]);
        }
        
        return minC;
        
    }
};