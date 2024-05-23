#include<bits/stdc++.h>
using namespace std;

bool Dfs(int src,int dest,vector<vector<int>> &adj,vector<bool> &visited){
    if(src==dest)
        return true;

    visited[src]=true;

    for(auto itr:adj[src]){
        if(!visited[itr]){
            return Dfs(itr, dest, adj, visited);
        } 
    }
    return false;
}
int main(){
    int n;
    cin>>n;

    vector<vector<int>>matrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int v;
            cin>>matrix[i][j];
        }
    }
    int src,dest;
    cin>>src;
    cin>>dest;
    src--;
    dest--;
    //converting to adjacency
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    vector <bool>visited(n,false); 
    if(Dfs(src,dest,adj,visited))
        cout<<"Yes Path Exist";
    else
        cout<<"No Path Exist";
}