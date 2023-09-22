//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
     vector<int> find(int arr[], int n , int x )
    {
        int a = -1, b = -1;
        int start = 0, end = n-1;
        int mid = 0;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(arr[mid] == x)
            {
                a = mid;
                b = mid;
                break;
            }
            else if(arr[mid]>x)
            end = mid-1;
            else start = mid + 1;
        }
        
       if(a == -1) return {a,b}; 
       while(a>=0 && b<n && arr[a] == arr[mid] || arr[b] == arr[mid])
       {
           if(arr[a] == arr[mid])
           a--;
           if(arr[b] == arr[mid])
           b++;
       }
    
        return {a+1,b-1};
      
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends