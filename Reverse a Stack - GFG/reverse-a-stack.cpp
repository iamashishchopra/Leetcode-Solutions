//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(stack<int>& st,stack<int> &extra){
        if(st.size()==0)
            return ;
        int temp = st.top();
        st.pop();
        helper(st,extra);
        while(!st.empty()){
            int val = st.top();
            extra.push(val);
            st.pop();
        }
        st.push(temp);
        while(!extra.empty()){
            int val = extra.top();
            st.push(val);
            extra.pop();
        }
    }
    void Reverse(stack<int> &st){
        stack<int> extra;
        helper(st,extra);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends