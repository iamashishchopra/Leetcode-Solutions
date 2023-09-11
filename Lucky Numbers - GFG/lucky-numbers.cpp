//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool isLucky(int n) {
        int whichPlaceNumbersDeleted = 2; // (n=5) => 1,2,3,4,5
        int totalNumberRemains = n;
        while(totalNumberRemains>=whichPlaceNumbersDeleted)
        {
            if(totalNumberRemains%whichPlaceNumbersDeleted==0)return 0; // last Number will be removed i.e given number
            
            totalNumberRemains = totalNumberRemains - totalNumberRemains/whichPlaceNumbersDeleted;
            
            whichPlaceNumbersDeleted++;
        }
        return 1;
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends