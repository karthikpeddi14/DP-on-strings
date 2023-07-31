// tabulated
class Solution {
public:
    int minInsertions(string s) 
    {
        int n= s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1 ; i>=0; i--)
        {
            for(int j=i ; j<n ; j++)
            {
                if(j==i) dp[i][j] = 1;
                else if(s[i]==s[j]) dp[i][j] = 2+dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return n-dp[0][n-1];
    }
};
// tabulated

// space optimated
class Solution {
public:
    int minInsertions(string s) 
    {
        int n= s.size();
        vector<int> next(n,0),cur(n,0);
        for(int i=n-1 ; i>=0; i--)
        {
            for(int j=i ; j<n ; j++)
            {
                if(j==i) cur[j] = 1;
                else if(s[i]==s[j]) cur[j] = 2+next[j-1];
                else cur[j] = max(next[j],cur[j-1]);
            }
            next = cur;
        }
        return n-next[n-1];
    }
};
// space optimum
