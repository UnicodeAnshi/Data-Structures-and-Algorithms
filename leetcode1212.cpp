#include<bits/stdc++.h>
using namespace std;
class Solution {
    int help(vector<vector<int>>& grid,int i, int j,int n ,int m){
        if(i<0 || i>=n ||j<0 ||j>=m||grid[i][j]==0)
            return 0;
        int cur= grid[i][j];
        grid[i][j]=0;
        int d=help(grid,i+1,j,n,m);
        int u=help(grid,i-1,j,n,m);
        int r=help(grid,i,j+1,n,m);
        int l=help(grid,i,j-1,n,m);
        grid[i][j]=cur;
        return cur+max({l,d,u,r,l});
    }
public:
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int result=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    result=max(result,help(grid,i,j,n,m));
                }
            }
        }
        return result;
    }
};