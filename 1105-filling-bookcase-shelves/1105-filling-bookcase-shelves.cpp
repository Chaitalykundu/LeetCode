class Solution {
public:
    int n;
    int width;
    int t[1001][1001];
    int solve(int i,int sw,vector<vector<int>>& books,int maxHeight){
        if(i>=n)
        return maxHeight;
        if(t[i][sw]!=-1)
        return t[i][sw];
        int booksW=books[i][0];
        int booksH=books[i][1];
        int keep=INT_MAX;
        int skip=INT_MAX;
        if(booksW<=sw){
            
            keep=solve(i+1,sw-booksW,books,max(maxHeight,booksH));
        }
       
            skip=maxHeight+solve(i+1,width-booksW,books,booksH);
        
        return t[i][sw]=min(skip,keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        width=shelfWidth;
        memset(t,-1,sizeof(t));
        return solve(0,shelfWidth,books,0);
    }
};