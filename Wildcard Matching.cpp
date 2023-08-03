// memo
class Solution {
public:
    bool f(string& s, string& t, int i, int j,vector<vector<int>>& dp)
    {
        if(j<0 && i<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0)
        {
            for(int k=0; k<=j ;k++ ) if(t[k]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j] || t[j]=='?') return dp[i][j] = f(s,t,i-1,j-1,dp);
        if(t[j]=='*') return dp[i][j] = f(s,t,i-1,j,dp) | f(s,t,i,j-1,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s,p,n-1,m-1,dp);
    }
};
// memo

// tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        
        dp[0][0] = true;
        for(int i=1 ; i<=n ; i++) dp[i][0] = false;
        for(int j=1; j<=m ; j++) 
        {
            bool con = (p[j-1]=='*');
            dp[0][j] = con & dp[0][j-1];
        }

        for(int i=1; i<=n ; i++)
        {
            for(int j=1; j<=m ;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')  dp[i][j] = dp[i][j-1] | dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};
// tabulation

// space opti
class Solution {
public:
    bool isMatch(string s, string p) {
    //     int n=s.size();
    //     int m=p.size();
    //     vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        
    //     dp[0][0] = true;
    //     for(int i=1 ; i<=n ; i++) dp[i][0] = false;
    //     for(int j=1; j<=m ; j++) 
    //     {
    //         bool con = (p[j-1]=='*');
    //         dp[0][j] = con & dp[0][j-1];
    //     }

    //     for(int i=1; i<=n ; i++)
    //     {
    //         for(int j=1; j<=m ;j++)
    //         {
    //             if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
    //             else if(p[j-1]=='*')  dp[i][j] = dp[i][j-1] | dp[i-1][j];
    //         }
    //     }
    //     return dp[n][m];
    // }
        int n=s.size();
        int m=p.size();
        vector<bool> prev(m+1,0),cur(m+1,0);
        
        prev[0] = true;
        for(int j=1; j<=m ; j++) 
        {
            bool con = (p[j-1]=='*');
            prev[j] = con & prev[j-1]; 
            if(prev[j]==false) break;        
        }

        for(int i=1; i<=n ; i++)
        {
            cur[0] = false;
            for(int j=1; j<=m ;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?') cur[j] = prev[j-1];
                else if(p[j-1]=='*')  cur[j] = cur[j-1] | prev[j];
                else cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }
};
// space opti

// further

// further
