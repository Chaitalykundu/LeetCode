//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void dfs(vector<vector<int>>& grid,int r,int j,int id,int &count)
{
    grid[r][j] = id;
        int nr[] = {-1,0,1,0};
        int nc[] = {0,1,0,-1};
        for(int i = 0;i<4;i++)
        {
            int newr = r + nr[i];
            int newc = j + nc[i];
            if(newr>=0 && newr<grid.size() && newc<grid[0].size() && newc>=0 && grid[newr][newc]==1)
            {
                count++;
                dfs(grid,newr,newc,id,count);
            }
        }
    }
    bool check(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j<m && j>=0)
        return true;
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        unordered_map<int,int> mp;
        int id = 2;
        int n = grid.size();
        int m = grid[0].size();
        int i;
        int j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count = 1;
                    dfs(grid,i,j,id,count);
                    mp[id] = count;
                    id++;
                }
            }
        }
        int ans = INT_MIN;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int> s;
                    int sum=1;
                    if(check(i-1,j,n,m) && s.find(grid[i-1][j])==s.end())
                    {
                        sum+=mp[grid[i-1][j]];
                        s.insert(grid[i-1][j]);
                    }
                    if(check(i,j-1,n,m) && s.find(grid[i][j-1])==s.end())
                    {
                        sum+=mp[grid[i][j-1]];
                        s.insert(grid[i][j-1]);
                    }
                    if(check(i+1,j,n,m) && s.find(grid[i+1][j])==s.end())
                    {
                        sum+=mp[grid[i+1][j]];
                        s.insert(grid[i+1][j]);
                    }
                    if(check(i,j+1,n,m) && s.find(grid[i][j+1])==s.end())
                    {
                        sum+=mp[grid[i][j+1]];
                        s.insert(grid[i][j+1]);
                    }
                    ans=max(ans,sum);
                }
            }
        }
        
        return (ans==INT_MIN)?n*m:ans;
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