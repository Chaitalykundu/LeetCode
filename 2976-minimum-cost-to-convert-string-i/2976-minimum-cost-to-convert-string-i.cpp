class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> mat(26,vector<long long>(26,INT_MAX));
        int n=original.size();
        for(int i=0;i<n;i++){
            mat[(original[i]-'a')][(original[i]-'a')]=0;
            mat[(changed[i]-'a')][(changed[i]-'a')]=0;
        }
        for(int i=0;i<n;i++){
            mat[original[i]-'a'][changed[i]-'a']=min(mat[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if( mat[i][via]!=INT_MAX && mat[via][j]!=INT_MAX){
                        mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                    }
                }
            }
        }
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<26;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(mat[source[i]-'a'][target[i]-'a']!=INT_MAX){
                ans+=mat[source[i]-'a'][target[i]-'a'];
            }
            else return -1;
        }
        return ans;
    }
};