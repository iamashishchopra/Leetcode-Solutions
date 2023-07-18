//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		 int LongestRepeatingSubsequence(string str){
            int l=str.length();
            vector<int> prev(l+1, 0);
            vector<int> curr(l+1);
            curr[0]=0;
            for(int i=0; i<l; i++) {
                for(int j=0; j<l; j++) {
                    if(i!=j && str[i]==str[j]) {
                        curr[j+1]=1+prev[j];
                    }
                    else {
                        curr[j+1]=max(curr[j], prev[j+1]);
                    }
                }
                prev=curr;
            }
            return prev[l];
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends