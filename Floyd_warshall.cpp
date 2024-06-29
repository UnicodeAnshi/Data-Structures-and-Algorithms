#include<bits/stdc++.h>
using namespace std;
//it is a multisouce shortest path algo which can detect -ve cycles as well
void short_distance(vector<vector<int>>&matrix){
    int n=matrix.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1&&j!=i){
                matrix[i][j]=INT_MAX;
            }
            if(i==j){
                matrix[i][j]=0;
            }
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INT_MAX) {
                matrix[i][j] = -1;
            }
        }
    }
    
} 

int main()
{
        int V;
        cin >> V ;
        vector<vector<int>> graph(V,vector<int>(V,0));
        //taking -1 as infinity
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cin>>graph[i][j];
            }
        }
        short_distance(graph);
        cout<<"\n\n";
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(graph[i][j]==-1)
                cout<<"INF"<<" ";
                else
                cout<<graph[i][j]<<" ";
            }
            cout<<"\n";
        }        
        
    

    return 0;
}

