#include<bits/stdc++.h>
using namespace std;
struct Task{
    int time;
    int end;
    int index;
};
bool cmp(Task a,Task b){
    return a.end<b.end;
}
int main(){
    int n;
    cin>>n;
    vector<int>times(n),end(n);
    for(int i=0;i<n;i++){
        cin>>times[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    vector<Task> tasks(n);
    for(int i=0;i<n;i++){
        tasks[i]={times[i],end[i],i+1};
    }
    sort(tasks.begin(),tasks.end(),cmp);
    vector<int> taskadded;
    int currentTime = 0;
    int maxTasks =0;

    for (int i = 0; i < n; i++) {
        if (currentTime + tasks[i].time <= tasks[i].end) {
            currentTime += tasks[i].time;
            taskadded.push_back(tasks[i].index);
            maxTasks++;
        }
    }

    cout<<"Max number of tasks = "<<maxTasks<<endl;
    cout<<"Selected Task Numbers ";
    for(auto itr:taskadded){
        cout<<itr<<" ";
    }

}