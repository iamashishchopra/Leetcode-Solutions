//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {
       //Our ans set lies between 1 to n+1 
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]>0 && arr[i]<n+1)
           {
             arr[cnt]=arr[i];
             cnt++;
           }
           
       }
       // Apply swap sort on element in range [1,n]
       for(int i=0;i<cnt;i++)
       {
            while(arr[i]!=i+1)
            {
                if(arr[i]-1<cnt && arr[arr[i]-1]!=arr[i])
                swap(arr[i],arr[arr[i]-1]);
                else
                break;
            }
       }
       if(cnt==0)
       return 1;
       for(int i=0;i<cnt;i++)
       {
           if(arr[i]!=i+1)
           return i+1;
       }
       return cnt+1;
       
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends