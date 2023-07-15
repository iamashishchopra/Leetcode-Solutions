//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
     void deleteMid(stack<int>&s, int n)//n=sizeOfStack
    {
        
        if(s.size()==(n+1)/2){
            s.pop();
            return;
        }
        int temp=s.top();
        s.pop();
        deleteMid(s,n);//here recursion will save in stack frame
        s.push(temp);//and with their values temp of different recursion calls which are saved in stack frame and then return after invoking the base condition 
    }               //which in return push their values in each stackframe
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends