#include<bits/stdc++.h>
using namespace std;

struct item{
    int w;
    int v;
    int idx;
};
bool cmp(item a,item b){
    double r1 = (double)a.v / (double)a.w;
    double r2 = (double)b.v / (double)b.w;
    return r1 > r2;
}
int main(){
    int n;
    cin>>n;
    vector<int> weights(n),values(n);

    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int capacity=0;
    cin>>capacity;
    
    vector<item> items(n);
    for(int i=0;i<n;i++){
        items[i]={weights[i],values[i],i+1};
    }
    sort(items.begin(),items.end(),cmp);
    vector<pair<int, double>> selectedItems;
    double totalValue =0.0;
    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;
        
        if (items[i].w <= capacity) {
            capacity -= items[i].w;
            totalValue += items[i].v;
            selectedItems.push_back({items[i].idx, 1.0});
        } else {
            // Take fraction of the item
            double fraction = (double)capacity / (double)items[i].w;
            totalValue += items[i].v * fraction;
            selectedItems.push_back({items[i].idx, fraction});
            capacity = 0;
        }
    }
    cout << "Maximum value: " << fixed << setprecision(2) << totalValue << endl;
    cout << "item-weight" << endl;
    for (const auto& item : selectedItems) {
        cout<<item.first<<"-"<<(int)item.second<<endl;
    }
}