//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    unordered_map<int,int> mp;
    
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int name, int n)
    {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 || vis[i][j])
        {
            return 0;
        }
        
        vis[i][j]=true;
        
        grid[i][j]=name;
        
        int count = 1+ dfs(i+1,j,grid,vis,name,n) + dfs(i-1,j,grid,vis,name,n) + dfs(i,j+1,grid,vis,name,n) + dfs(i,j-1,grid,vis,name,n);
        
        return count;
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        int name = 2;
        int n=grid.size();
        
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int count = dfs(i,j,grid,vis,name,n);
                    mp[name]=count;
                    name++;
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int down=(i+1<n)?grid[i+1][j]:0;
                    int up=(i-1>=0)?grid[i-1][j]:0;
                    int right=(j+1<n)?grid[i][j+1]:0;
                    int left=(j-1>=0)?grid[i][j-1]:0;
                    
                    
                    set<int> s;
                    s.insert(down);
                    s.insert(up);
                    s.insert(left);
                    s.insert(right);
                    
                    int res=1;
                    
                    for(int val:s)
                    {
                        res=res+mp[val];
                    }
                    
                    ans=max(ans,res);
                }
            }
        }
        
        if(ans==0)                // if all the values in grid is 1
        {
            return n*n;
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends