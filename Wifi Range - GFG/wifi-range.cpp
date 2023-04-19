//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        int mini = -1,maxi = -1;
        int cnt = 0;
        
        if(x>=n-1)
        {
            for(int i = 0;i<n;i++)
            if(s[i] == '1')
            return true;
        }
        
        for(int i = 0;i<n;i++)
        {
            if(maxi>=n-1)return true;
            
            if(cnt == 0)
            if(s[i] == '1')
            {
                cnt++;
                mini = i - x;
                maxi = i + x;
                if(mini > 0)
                {
                    return false;
                }
                mini = 0;
            }
            
            if(s[i] == '1')
            {
                if(i>=mini && i<=maxi)
                {
                    maxi = i+x;
                }
                else
                {
                    if((i-x)<=(maxi+1))
                    {
                        maxi = i+x;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // cout<<mini<<" "<<maxi<<" ";
        if(maxi>=n-1)
        return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends