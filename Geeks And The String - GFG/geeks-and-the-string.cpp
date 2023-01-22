//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char> st;
        int i=0;
        while(i<s.length()){
            if(st.size()==0){
                st.push(s[i]);
                
            }
            else if(st.size()>0&&st.top()==s[i]){
                st.pop();
            }
            else if(st.size()>0&&st.top()!=s[i]){
                st.push(s[i]);
            }
            i++;
        }
        string s1;
        while(st.size()>0){
            s1+=st.top();
            st.pop();
        }
        reverse(s1.begin(),s1.end());
        if(s1.size()==0){
            return "-1";
        }
        return s1;   
 
}
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends