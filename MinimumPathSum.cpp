class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=grid.size();
        if(m==0)    return 0;
        int n=grid[0].size();
        if(n==0)    return 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) {
                    continue;

                }
                int min=1<<31-1;
                if(i>0)
                    min=min<grid[i-1][j]?min:grid[i-1][j];
                if(j>0)
                    min=min<grid[i][j-1]?min:grid[i][j-1];
                grid[i][j]+=min;
            }
        }

        return grid[m-1][n-1];
    }
};