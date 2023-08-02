// recur and memo
class Solution {
public:
    int f(string& s, string& t, int i, int j,vector<vector<int>>& dp)
    {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=f(s,t,i-1,j-1,dp)+f(s,t,i-1,j,dp);
        else return dp[i][j] = f(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s,t,n-1,m-1,dp);
    }
};
// recur and memo

// tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=0 ; i<=n; i++) dp[i][0] = 1;

        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m; j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
// tabulation

// space opti
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1,0),cur(m+1,0);
        prev[0]=cur[0] =1;

        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m; j++)
            {
                if(s[i-1]==t[j-1]) cur[j] = prev[j-1] + prev[j];
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        return (int)prev[m];
    }
};
// space opti

// further
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1,0);
        prev[0] =1;

        for(int i=1 ; i<=n ; i++)
        {
            for(int j=m ; j>=1; j--)
            {
                if(s[i-1]==t[j-1]) prev[j] = prev[j-1] + prev[j];
                else prev[j] = prev[j];
            }
        }
        return (int)prev[m];
    }
};
// further
