class Solution {
public:
    
    int solveRec(string s1, string s2, int m, int n)

    {

        //base case
        if(m == 0 || n == 0){
            return 0;
        }

        if(s1[m-1] == s2[n-1])
        {
            return 1 + solveRec(s1, s2, m-1, n-1);
        }
        else{
            return max(solveRec(s1, s2, m-1, n), solveRec(s1, s2, m, n-1));
        }
        
    }

    // Top Down DP
    int solveMem(string s1, string s2, int m, int n, vector<vector<int>> &dp){

        if(m == 0 || n == 0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];

        }
        if(s1[m-1] == s2[n-1]){
            dp[m][n] =1 + solveMem(s1, s2, m-1, n-1, dp);
        }

        else{
            dp[m][n] = max(solveMem(s1, s2, m-1, n, dp), solveMem(s1, s2, m, n-1, dp));
        }

        return dp[m][n];
    }

    int solveTab(string s1, string s2){
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){

                if(s1[i-1] == s2[j-1]){

                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }
        return dp[m][n];
    }

    int solveTabSpaceOptimised(string s1, string s2){

        int m = s1.length();
        int n = s2.length();

        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int i=1; i<=m; i++){
            
            for(int j=1; j<=n; j++){

                if(s1[i-1] == s2[j-1])
                {
                    curr[j] = 1 + prev[j-1];

                }

            else{

                curr[j] = max(prev[j], curr[j-1]);

            }
        }

        prev = curr;

    }

    return prev[n];
    }

    int longestCommonSubsequence(string s1, string s2)  
    {
        int m = s1.length();
        int n = s2.length();

        return solveTabSpaceOptimised(s1, s2);
    }   


};