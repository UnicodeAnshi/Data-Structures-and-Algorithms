#include<bits/stdc++.h>
using namespace std;
int minimumcost(vector<int> &files){
    priority_queue<int,vector<int>,greater<int>> minheap;

    for(auto size: files){
        minheap.push(size);
    }
    int totalcost =0;

    while(minheap.size()>1){
        int first=minheap.top();
        minheap.pop();
        int second=minheap.top();
        minheap.pop();
        int merge=first+second;
        totalcost+=merge;
        minheap.push(merge);
    }
    return totalcost;
}
int main(){
   int n;
    	cin>>n;

    	vector<int>files(n);
    	for (int i=0;i<n;i++)
    	{
        		cin>>files[i];
    	}

    	int result=minimumcost(files);
    	cout<<result<<endl;
    	return 0;
}
 