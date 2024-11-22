class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        map<string,int> mp;
        int max1=INT_MIN,max2=INT_MIN;

        for(int i=0; i<m; i++)
        {
            string temp;
            for(int j=0;j<n;j++)
            {
               temp=temp+to_string(matrix[i][j]);
            }

            mp[temp]++;
            int t=mp[temp];
            max1=max(max1,t);
        }

        for(int i=0;i<m;i++)
        {
            string temp;
            string ori;
            for(int j=0;j<n;j++)
            {
                  int u=matrix[i][j];
                  ori=ori+to_string(u);
                  int k=1-matrix[i][j];
                  temp=temp+to_string(k);
            }

            if(mp[temp]>0)
            {
                int ans=mp[temp]+mp[ori];
                max2=max(max2,ans);
            }
        }

        if(max1>max2)
        return max1;

        return max2;
    }
};
