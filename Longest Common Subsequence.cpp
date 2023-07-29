// recursion
class Solution {
public:
    int f(string& text1, string& text2, int ptr1 ,int ptr2)
    {
        if(ptr1<0 || ptr2<0) return 0;
        
        if(text1[ptr1] == text2[ptr2])
        {
            return 1+f(text1,text2,ptr1-1,ptr2-1);
        }
        return max(f(text1,text2,ptr1-1,ptr2),f(text1,text2,ptr1,ptr2-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return f(text1,text2,n-1,m-1);
    }
};
// recursion

// memo
class Solution {
public:
    int f(string& text1, string& text2, int ptr1 ,int ptr2, vector<vector<int>>& dp)
    {
        if(ptr1<0 || ptr2<0) return 0;
        if(dp[ptr1][ptr2] !=-1) return dp[ptr1][ptr2];

        if(text1[ptr1] == text2[ptr2])
        {
            return dp[ptr1][ptr2] =1+f(text1,text2,ptr1-1,ptr2-1,dp);
        }
        return dp[ptr1][ptr2] = max(f(text1,text2,ptr1-1,ptr2,dp),f(text1,text2,ptr1,ptr2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(text1,text2,n-1,m-1,dp);
    }
};
// memo

// tabulation by my method  ( obvi messy)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0 ; i<m ; i++)
        {
            if(text1[0] == text2[i]) dp[0][i] = 1;
            else if(i>0) dp[0][i] = dp[0][i-1];
        }
        for(int i=0 ; i<n ; i++)
        {
            if(text2[0] == text1[i]) dp[i][0] = 1;
            else if(i>0) dp[i][0] = dp[i-1][0];
        }
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=1 ; j<m ; j++)
            {
                if(text1[i]==text2[j]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
// tabulation by my method  

// tabulation using strivers method - creating a space for negative index
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0 ; i<m ; i++)
        {
            dp[0][i] = 0;
        }
        for(int i=0 ; i<n ; i++)
        {
            dp[i][0] = 0;
        }
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
// tabulation using strivers method

// space opti
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(text1[i-1]==text2[j-1]) cur[j] = 1+prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};
// space opti
