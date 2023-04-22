//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        
        vector<pair<int, int>> vp;
        for(int i = 0; i<n; i++) vp.push_back({arr[i], i});
        sort(vp.begin(), vp.end());
        
        vector<pair<long long, long long>> prec(n, make_pair(0, 0));
        for(int i = 1; i<n; i++){
            prec[i].second += prec[i-1].second+vp[i-1].first;
            if(vp[i].first == vp[i-1].first) prec[i].first = prec[i-1].first;
            else prec[i].first = prec[i].second;
        }
        
        vector<long long> ans(n, 0);
        for(int i = 0; i<n; i++) ans[vp[i].second] = prec[i].first;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends