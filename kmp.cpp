
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
    public:
        void computelps(vector<int> & lps,string pat,int m){
            int i=1,length=0;
            lps[0]=0;
            while(i<m){
                if(pat[i]==pat[length]){
                    length++;
                    lps[i]=length;
                    i++;
                }
                else{
                    if(length!=0){
                        length=lps[length-1];
                    }
                    else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            int i=0,j=0;
            int m=pat.size();
            vector<int> lps(m) ,ans;
            int n=txt.size();
            computelps(lps,pat,m);
            while(i<n){
                if(pat[i]==pat[j]){
                    i++;
                    j++;
                }
                if(j==m){
                    ans.push_back(i-m+1);
                    j=lps[j-1];
                }
                if(i<n && txt[i]!=pat[j]){
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
