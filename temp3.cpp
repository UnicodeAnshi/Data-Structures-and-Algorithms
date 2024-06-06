//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int knapSack(int w, int wt[], int val[], int n) 
    { 

    int W=w;
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(j<wt[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
        return dp[n][w];
    }
    }
};
