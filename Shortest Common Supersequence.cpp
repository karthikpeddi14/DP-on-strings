// my brute force method
class Solution {
public:
    string f(string text1, string text2) {
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
        
        int i = n;
        int j = m;
        string common;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                common = text1[i-1] + common;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        return common;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string com = f(str1,str2);
        int n = str1.size();
        int m = str2.size();
        int size = com.size();

        int i=0;
        int j=0;
        int index=0;
        string ans;
        while(index<size)
        {
            while(i<n && str1[i]!= com[index])
            {
                ans += str1[i];
                i++;
            }
            i++;
            while(j<m && str2[j]!= com[index])
            {
                ans += str2[j];
                j++;
            }
            j++;
            if(index<size) 
            {
                ans+=com[index];
                index++;
            }
        }
        while(i<n)
        {
            ans+= str1[i];
            i++;
        }
        while(j<m)
        {
            ans+= str2[j];
            j++;
        }
        return ans;
    }
};
// my brute force method

// strivers method
class Solution {
public:
    string f(string text1, string text2) {
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
        
        int i = n;
        int j = m;
        string ans;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                ans = text1[i-1] + ans;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) 
            {
                ans = text1[i-1] + ans;
                i--;
            }
            else
            {
                ans = text2[j-1] + ans;
                j--;
            } 
        }
        while(i>0)
        {
            ans = text1[i-1] + ans;
            i--;
        }
        while(j>0)
        {
            ans = text2[j-1] + ans;
            j--;
        }
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return f(str1,str2);
    }
};
// strivers method
