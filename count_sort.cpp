#include<bits/stdc++.h>
using namespace std;
void countSort(vector<char> &arr){
    vector <int> helper(26,0);
    for(auto itr: arr){
        helper[itr-'a']++;
    }
   int maxCount = 0;
    char maxChar = '\0';
    for (int i = 0; i < 26; i++) {
        if (helper[i] > maxCount) {
            maxCount = helper[i];
            maxChar = i + 'a'; 
        }
    }
    if(maxCount == 1)
        cout<<"No Duplicates Present"<<endl;
    else 
        cout<<maxChar<<"-"<<maxCount;
}
int main(){
   int n;
   cin>>n;
   while(n--){
        vector<char> arr;
        int v;
        cin>>v;
        while(v--){
            char ch;
            cin>>ch;
            arr.push_back(ch);
        }
        countSort(arr);
   }
}