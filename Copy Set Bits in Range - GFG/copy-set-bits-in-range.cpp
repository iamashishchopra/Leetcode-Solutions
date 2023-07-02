//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        vector<int> bitx(32 , 0),bity(32 , 0);
        int j = 0;
        while(x > 0){
            bitx[j] = x % 2;
            j++;
            x /= 2;
        }
        j=0;
        while(y > 0){
            bity[j] =y % 2;
            j++;
            y /= 2;
        }
        for(int i = l-1; i<r; i++){
            if(bity[i] == 1)
                bitx[i] = bity[i];
        }
        
        int n=0;
        int base=1;
        for(int i=0; i<bitx.size(); i++){
            n += base * bitx[i];
            base *= 2;
        }
        return n;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends