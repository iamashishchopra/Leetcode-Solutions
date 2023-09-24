//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int,int> res;
        vector <int> dub;
        
        for(int i = 0 ; i<n ; i++) res[arr[i]]++;
        for(int i = 0 ; i<n ; i++){
            if(res[arr[i]]>1) {dub.push_back(arr[i]);
                
                res[arr[i]]=0;
            };
        }
        if(dub.empty()) dub.push_back(-1);
        sort (dub.begin(), dub.end());
        return dub;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends