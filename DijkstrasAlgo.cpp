#include<bits/stdc++.h>
using namespace std;
void printPath(vector<int> &parent,int j){
    if(parent[j]==-1)
        return;
    cout<<parent[j]+1<<" ";
    printPath(parent,parent[j]);
}
int minDistance(vector<int> dist,vector<bool> sptSet,int V){
    int min=INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(!sptSet[v] && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}
void dijkstras(vector<vector<int>> &graph,int src,int V){
    //initialsing the values
    vector<int> dist(V,INT_MAX);
    vector<bool> sptSet(V,false);
    vector<int> parent(V,-1);
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=minDistance(dist,sptSet,V);
        sptSet[u]=true;
        for(int v=0;v<V;v++){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
                parent[v]=u;
            }
        }
    }
    //printing the result
    for (int i = 0; i < V; i++) {
        cout << i + 1 <<" ";

        if(dist[i]==INT_MAX){
            cout<<"infinity"<<endl;
            continue;
        }
        printPath(parent,i);
        cout<<" : "<<dist[i]<<endl;
    }
}
int main(){
    int n;
    cin>>n;

    vector<vector<int>>graph(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int v;
            cin>>graph[i][j];
        }
    }

    dijkstras(graph,0,n);
}
