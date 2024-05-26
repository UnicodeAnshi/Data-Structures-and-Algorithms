
#include<bits/stdc++.h>
using namespace std;

class disjointset{
    vector<int> size,parent;
    public:
        disjointset(int n){
            size.resize(n,1);
            parent.resize(n);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUlp(int u){
            if(u==parent[u])
                return u;

            return parent[u]=findUlp(parent[u]);
        }
        void unionbysize(int u,int v){
            int ulp_u=findUlp(u);
            int ulp_v=findUlp(v);

            if(ulp_u==ulp_v)
                return;

             if(size[ulp_u] <size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }       
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }                      
        }
};

class Solution {
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> edges){
        sort(edges.begin(),edges.end());
        disjointset ds(V);
        int mswt=0;

        for(auto &itr: edges){
            int wt=itr[0];
            int u=itr[1];
            int v=itr[2];
            
            if(ds.findUlp(u)!=ds.findUlp(v)){
                mswt+=wt;
                ds.unionbysize(u,v);
            }
        }
        return mswt;
    }
};

int main()
{
        int V;
        cin >> V ;
        vector<vector<int>> graph(V,vector<int>(V,0));
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cin>>graph[i][j];
            }
        }
        vector<vector<int>> adj;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                if(graph[i][j]!=0){
                    adj.push_back({graph[i][j],i,j});
                }
        }
    }
        
        Solution obj;
    	cout <<"Minimum Spanning Tree Weight:"<< obj.spanningTree(V, adj) << "\n";

    return 0;
}