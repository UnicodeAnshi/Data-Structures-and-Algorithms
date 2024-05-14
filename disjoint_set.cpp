#include<bits/stdc++.h>
using namespace std;
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

            if(size[ulp_u]<size[ulp_v]){
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
int main(){
    disjointset g(7);
    g.unionbysize(1,2);
    g.unionbysize(4,5);
    g.unionbysize(2,3);
    g.unionbysize(6,7);
    if(g.findUlp(3)==g.findUlp(7))
        cout<<"is same"<<endl;
    else
        cout<<"not same"<<endl;
    g.unionbysize(5,6);
    g.unionbysize(3,7);
    if(g.findUlp(3)==g.findUlp(7))
        cout<<"is same"<<endl;
    else
        cout<<"not same";
}