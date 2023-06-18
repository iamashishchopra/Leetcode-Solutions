//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int i = 1, j = N;
        bool flag = false; 
        while(j-i+1 > K){
            if(j-i+1 > K){
                i += K;
                flag = true; //indicating that tickets are distributed from the front(now turn for back)
            }
            if(j-i+1 > K){
                j -= K;
                flag = false; //indicating that tickets are distributed from the back(and now turn for front)
            }
        }
        if(j-i+1 == K && flag) return i;
        if(j-i+1 == K && !flag) return j;
        return flag ? i : j;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends