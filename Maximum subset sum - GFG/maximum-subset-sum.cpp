//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
   long long recursive_approach(vector<int>&arr,int index,int n){
        if(index>=n){
            return 0;
        }
        
        long long take,notTake;
        
        take=arr[index]+recursive_approach(arr,index+1,n);
        notTake=(index+1>=n?0:arr[index+1]+ recursive_approach(arr,index+2,n));
        
        return max(take,notTake);
    }
    long long memoization_approach(vector<int>&arr,int index,int n,vector<int>&t){
        if(index>=n){
            return 0;
        }
        
        long long take,notTake;
        
        if(t[index]!=-1){
            return t[index];
        }
        
        take=arr[index]+memoization_approach(arr,index+1,n,t);
        notTake=(index+1>=n?0:arr[index+1]+ memoization_approach(arr,index+2,n,t));
        
        return t[index]=max(take,notTake);
    }
    
    long long tabulation_approach(vector<int>&arr,int n){
        vector<int>t(n+2,0);
        long long take,notTake;
        for(int i=n-1;i>=0;i--){
            take=arr[i]+t[i+1];
            notTake=(i+1>=n?0:arr[i+1]+t[i+2]);
            t[i]=max(take,notTake);
        }
        return t[0];
    }
    
    long long spaceOptimized_approach(vector<int>&arr,int n){
        long long take,notTake,prev_1,prev_2;
        prev_1=0;
        prev_2=0;
        
        for(int i=n-1;i>=0;i--){
            take=arr[i]+prev_1;
            notTake=(i+1>=n?0:arr[i+1]+prev_2);
            prev_2=prev_1;
            prev_1=max(take,notTake);
        }
        
        return prev_1;
    }
    
  public:
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        // return recursive_approach(A,0,N);
        
        // vector<int>t(N,-1);
        // return memoization_approach(A,0,N,t);
        
        // return tabulation_approach(A,N);
        
        return spaceOptimized_approach(A,N);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends