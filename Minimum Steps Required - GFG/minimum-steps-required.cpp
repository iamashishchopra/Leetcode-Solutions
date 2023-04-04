//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int n=str.size()-1;
    if(n==1)
    return 1;
    
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(str[i-1]==str[0] && str[i-1]!=str[i])
                count++;
        }
        return count+1;
   
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends