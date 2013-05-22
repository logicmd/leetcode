class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.size() == 0) {
            return 0;
        }

        if(triangle.size() == 1) {
            return triangle[0][0];
        }

        for(int i = triangle.size() - 1; i >= 1; i--) {
            for(int j = 0; j <= i - 1; j++) {
                triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
            }
        }

        return triangle[0][0];
    }
};