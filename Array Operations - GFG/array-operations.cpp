//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int start = 0,end = 0, count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=0) 
            {
                start = i;
            
                while(arr[i+1]!=0 && i<n-1) i++;
                end = i;
            
                count++;
            }
            
        }
        if(count==1 && end==n-1) return -1;
        else return count;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends