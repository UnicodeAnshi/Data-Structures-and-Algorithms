#include <bits/stdc++.h>
using namespace std;
//using DFS to detect a cycle in a d. graph
//to check if a graph is cyclic on the ame path it has to visited again
bool dfsCheck(int i,vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathVis){
    vis[i]=1;
    pathVis[i]=1;
    //traversing for adjacent nodes

    for(auto itr:adj[i]){
        if(!vis[itr]){
            if(dfsCheck(itr,adj,vis,pathVis))
                return true;
        }
        //if the  node has been visited
        //but visited on same path
        else if(pathVis[itr])
            return true;
    }
    pathVis[i]=0;
    return false;
}
bool isCyclic(int n,vector<vector<int>> &adj){
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfsCheck(i,adj,vis,pathVis))return true;
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
    //converting to adjacency
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                adj[i].push_back(j);
            }
        }
    }
    if(isCyclic(n,adj))
        cout<<"Yes Cycle Exists";
    else{
        cout<<"No Cycle Exists";
    }
}