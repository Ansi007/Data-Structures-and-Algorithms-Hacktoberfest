class Solution {
    bool solve(string s1 , string s2 , string s3, int i , int j , vector<vector<int>> &dp)
    {
        if(i == s1.size() && s2.size() == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s3[i+j])
             dp[i][j] = solve(s1 , s2 , s3 , i+1 , j , dp);
        if(dp[i][j] == 1) return 1;
        if(s2[j] == s3[i+j])
            dp[i][j] = solve(s1, s2 ,s3 , i , j+1 , dp);
        if(dp[i][j] == 1) return dp[i][j];
        return dp[i][j] = 0;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        if(n+m != s3.size()) return 0;
        return solve(s1 , s2 , s3 , 0 , 0 , dp);
    }
};
