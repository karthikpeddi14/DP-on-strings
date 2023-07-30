// tabulation using logic
int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int ans=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j]= 0;
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
    
}
// tabulation using logic

// space opti
int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int ans=0;
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if(s1[i-1]==s2[j-1]) cur[j] = 1+prev[j-1];
            else cur[j]= 0;
            ans = max(ans,cur[j]);
        }
        prev = cur;
    }
    return ans;
    
}
// space opti
