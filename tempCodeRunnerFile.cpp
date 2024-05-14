#include <iostream>
#include <stack>
#include <algorithm>
#include<vector>
using namespace std;
void merge(int arr[], int l ,int mid ,int r,vector <int>&inversions,int &comparisons){
    int n1=mid-l+1;
    int n2=r-mid;
    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++)
        arr1[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        arr2[j]=arr[mid+1+j];
    
    int i=0,j=0,k=l;
    int inversionCount = 0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j])
            arr[k++]=arr1[i++];
        else{
            arr[k++]=arr2[j++];
            inversionCount+=n1-i;
        }
        comparisons++;
    }
    while(i<n1)
        arr[k++]=arr1[i++];
    while(j<n2)
        arr[k++]=arr2[j++];
    inversions.push_back(inversionCount);
}
void partition(int arr[], int l,int r,vector<int>&inversions,int &comparisons) {
    if(l<r){
        int mid=l+(r-l)/2;
        partition(arr,l,mid,inversions,comparisons);
        partition(arr,mid+1,r,inversions,comparisons);
        merge(arr,l,mid,r,inversions,comparisons);
    }
}
int main()
{
    int n;
    cin >> n;
    
    while (n)
    {
        int comparisons=0;
        vector <int>inversions;
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        partition(arr,0,size-1,inversions,comparisons);
        for (int i = 0; i < size; i++)
        {
            cout<< arr[i]<<" ";
        }
        cout<<"\ncomparisons = "<<comparisons<<endl;
       // cout<<"inversions = "<<comparisons<<endl;
        for(auto itr: inversions)
            cout<<itr<<" ";
        cout<<endl<<endl;
        
        n--;
    }
}
