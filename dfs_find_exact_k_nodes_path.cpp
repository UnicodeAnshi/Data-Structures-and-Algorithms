#include<bits/stdc++.h>
using namespace std;
void DFSsearch(vector<vector<int>> &edges,int src,int dest,int k,int current,int &ans,vector<bool> &visited){
    if(k<0)
        return;
    if(src==dest && k==0){
        ans=min(ans,current);
        return;
    }

    visited[src]=true;

    for(auto &edge :edges){
        if(edge[0]==src){
            int next=edge[1];
            int wt=edge[2];
            if(!visited[next]){
                DFSsearch(edges,next,dest,k-1,current+wt,ans,visited);
            }
        }
    }
    visited[src] = false;
}
int shortestPathWithExactlyKedges(vector<vector<int>>&edges,int v,int src,int dest,int k){
    int min_weight = INT_MAX;
    vector<bool> visited(v, false);
    DFSsearch(edges, src, dest, k, 0, min_weight, visited);
    return (min_weight == INT_MAX) ? -1 : min_weight;
}
int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }
    int src,dest,k;
    cin>>src;
    cin>>dest;
    src--;
    dest--;
    cin>>k;
    int ans=shortestPathWithExactlyKedges(edges,n,src,dest,k);
    if((ans)!=-1)
        cout<<"Weight of shortest path from ("<<src+1<<","<<dest+1<<") with "<<k<<" edges: "<<ans;
    else    
        cout<<"no path of length k is available";
}