//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
        int s=0,e=n-1;
    int mid;
    int firstind=-1;
    int lastind=-1;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==x){
            firstind=mid;
            e=mid-1;
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    s=0,e=n-1;
    
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==x){
            lastind=mid;
            s=mid+1;
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    if(firstind==-1){
        return 0;
    }
    return lastind-firstind+1;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends