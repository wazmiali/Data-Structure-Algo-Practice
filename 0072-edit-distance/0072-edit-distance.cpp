class Solution {
public:
    
    int solveRec(string s1, string s2, int m, int n){

        if(m == 0) return n;
        if(n == 0) return m;

        if(s1[m-1] == s2[n-1])
        {
            return solveRec(s1, s2, m-1, n-1);
        }

        int removeOp = solveRec(s1, s2, m-1, n);

        int insertOp = solveRec(s1, s2, m, n-1);

        int replaceOp = solveRec(s1, s2, m-1, n-1);

        return 1 + min({removeOp, insertOp, replaceOp});

    }

    int solveMem(string s1, string s2, int m, int n, vector<vector<int>> & dp)
    {
        if(m == 0) return n;
        if(n == 0) return m;

        if(dp[m][n] != -1) return dp[m][n];

        if(s1[m-1] == s2[n-1])
        {
           return dp[m][n] = solveMem(s1, s2, m-1, n-1, dp);
        }

        int removeOp = solveMem(s1, s2, m-1, n, dp);
        int insertOp = solveMem(s1, s2, m, n-1, dp);
        int replaceOp = solveMem(s1, s2, m-1, n-1, dp);

        dp[m][n] = 1 + min({removeOp, insertOp, replaceOp});
        return dp[m][n];
    }

    int solveTab(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp (m+1, vector<int>(n+1, 0));

        for(int i=0; i<=m; i++) dp[i][0] = i;
        for(int j=0; j<=n; j++) dp[0][j] = j;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }

                else{
                    int removeOp = dp[i-1][j];
                    int insertOp = dp[i][j-1];
                    int replaceOp = dp[i-1][j-1];
                    dp[i][j] = 1 + min({removeOp, insertOp, replaceOp});
                }
            }
        }

        return dp[m][n];
    }
    int solveTabSpaceOptimised(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int j=0; j<=n; j++){
            prev[j] = j;
        }

        for(int i = 1; i<=m; i++)
        {
            curr[0] = 1;

            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = prev[j-1];

                }
                else{

                    int removeOp = prev[j];
                    int insertOp = curr[j-1];
                    int replaceOp = prev[j-1];
                    curr[j] = 1 + min({removeOp, insertOp, replaceOp});
                }
            }
            prev = curr;
        }

        return prev[n];
    }

    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

         return solveTab(word1, word2); 
    }
};



