// recur and memo
class Solution {
public:
    int f(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {

        if(i<0 || j<0) return max(i+1,j+1);
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = f(text1,text2,i-1,j-1,dp);

        int insert = f(text1,text2,i,j-1,dp);
        int del = f(text1,text2,i-1,j,dp);
        int replace = f(text1,text2,i-1,j-1,dp);
        return dp[i][j] = 1+min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) 
    {
        int n=word1.size();
        int m=word2.size();
        if(n==0 || m==0) return max(n,m);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(word1,word2,n-1,m-1,dp);
    }
};
// recur and memo
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i=0 ; i<=m ; i++) dp[0][i] = i;
        for(int i=0 ; i<=n ; i++) dp[i][0] = i;

        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1; j<=m ; j++)
            {
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else
                {
                    int rep = 1+dp[i-1][j-1];
                    int add = 1+dp[i][j-1];
                    int del = 1+dp[i-1][j];
                    dp[i][j] = min(rep,min(add,del));
                }
            }
        }
        return dp[n][m];
    }
};
// recur and memo

// tabulation
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0), cur(m+1,0);

        for(int i=0 ; i<=m ; i++) prev[i] = i;
        for(int i=1 ; i<=n ; i++)
        {
            cur[0] = i;
            for(int j=1; j<=m ; j++)
            {
                if(word1[i-1]==word2[j-1]) cur[j] = prev[j-1];
                else
                {
                    int rep = 1+prev[j-1];
                    int add = 1+cur[j-1];
                    int del = 1+prev[j];
                    cur[j] = min(rep,min(add,del));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};
// tabulation
