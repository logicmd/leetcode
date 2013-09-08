class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(n==0)    return 0;
        int *dp=new int[n];
        dp[n-1]=0;
        int max=0;
        for(int i=n-2; i>=0; i--) {
            dp[i]=0;
            if(s[i]=='(') {
                int j=i+1+dp[i+1];
                if(j<n && s[j]==')') {
                    dp[i]=dp[i+1]+2;
                    if(j+1<n) {
                        dp[i]+=dp[j+1];
                    }
                }


                if(dp[i]>max)
                    max=dp[i];
            }
        }
        return max;
    }
};