// recur and memo
class Solution {
public:
    int f(string s, int i, int j,vector<vector<int>>& dp)
    {
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = 2+f(s,i+1,j-1,dp);

        return dp[i][j] = max(f(s,i+1,j,dp), f(s,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(s,0,n-1,dp);
    }
};
// recur and memo

// tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int j=i; j<n ; j++)
            {
                if(i==j) dp[i][j] = 1;
                else if(s[i]==s[j]) dp[i][j] = 2+dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
        
    }
};
// tabulation

// space opti
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        vector<int> next(n,0), cur(n,0);

        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int j=i; j<n ; j++)
            {
                if(i==j) cur[j] = 1;
                else if(s[i]==s[j]) cur[j] = 2+next[j-1];
                else cur[j] = max(next[j],cur[j-1]);
            }
            next = cur;
        }
        return next[n-1];
        
    }
};
// space opti
