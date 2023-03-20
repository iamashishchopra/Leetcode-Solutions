//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        vector<pair<int,int>>x,y;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(grid[i][j]=='X')x.push_back({i,j});
                else if(grid[i][j]=='Y')y.push_back({i,j});
        int ans=INT_MAX;
        for(auto i:x){
            int xi=i.first,xj=i.second;
            for(auto j:y){
                int yi=j.first,yj=j.second;
                ans=min(ans,(abs(xi-yi))+abs(xj-yj));
                if(ans==1)return 1;
            }
        }return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends