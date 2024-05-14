//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class disjointset{
    vector<int> size,parent,rank;
    public:
        disjointset(int n){
            size.resize(n+1,1);
            parent.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUlp(int u){
            if(u==parent[u])
                return u;

            return findUlp(parent[u]);
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
            else if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            } 
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }                      
        }

};
class Solution
{
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector <pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
                int node=itr[0];
                int weight=itr[1];
                
                edges.push_back({weight,{i,node}});
            }
        }
        //sorting
        sort(edges.begin(),edges.end());
        disjointset ds(V);
        int mswt=0;
        for(auto itr: edges){
            int wt=itr.first;
            int node=itr.second.first;
            int adjnode=itr.second.second;
            
            if(ds.findUlp(node)!=ds.findUlp(adjnode)){
                mswt+=wt;
                ds.unionbysize(node,adjnode);
            }
        }
        return mswt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends