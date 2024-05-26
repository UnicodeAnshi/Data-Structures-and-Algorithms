#include<bits/stdc++.h>
using namespace std;
int SpanningTree(int V,vector<vector<pair<int,int>>>adj){
    vector <int> vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node = it.second;
        int wt =it.first;

        if(vis[node]==1)continue;
        vis[node]=1;
        sum+=wt;
        for(auto it: adj[node]){
            int adjNode =it.first;
            int edw=it.second;
            if(!vis[adjNode]){
                pq.push({edw,adjNode});
            }
        }
    }
    return sum;
}
int main(){
    int V;
    cin>>V;

    vector<vector<int>> graph(V,vector<int>(V,0));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }
    //converting to adjacency
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
        if(graph[i][j]!=0){
            int u,v,w;
            u=i;
            v=j;
            w=graph[i][j];
            adj[u].emplace_back(v,w);
        }
       }
    }
    int ans=SpanningTree(V,adj);
     cout<<"Minimum Spanning Weight :"<<ans;

}
