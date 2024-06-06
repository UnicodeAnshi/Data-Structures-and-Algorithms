#include<bits/stdc++.h>//<bits/stc++.h>
using namespace std;
bool customcomp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.second.second<b.second.second;
}
int main(){
    priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> ,decltype(customcomp)> pq(customcomp);
    pq.push({1, {2, 3}});
    pq.push({4, {5, 6}});
    pq.push({4, {5, 1}});
    pq.push({4, {5, 2}});
    pq.push({4, {5, 3}});

    while (!pq.empty()) {
        auto top = pq.top();
        cout << top.first << " " << top.second.first << " " << top.second.second << endl;
        pq.pop();
    }

}