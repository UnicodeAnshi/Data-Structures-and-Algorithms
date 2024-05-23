#include<bits/stdc++.h>
using namespace std;
bool Bfs(vector<vector<int>> &adj,int n){
    vector <bool> color(n,-1);
    queue<int> q;

    for(int i=0;i<n;i++){
        if(color[i]==-1)//node not colored
        {
            q.push(i);
            color[i]=0;
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int itr: adj[node]){
                
            }
        }
    }

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

    if(Bfs(adj,n))
        cout<<"Yes Path Exist";
    else
        cout<<"No Path Exist";
}