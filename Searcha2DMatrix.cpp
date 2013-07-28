class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;
        int row = -1;
        int s = 0, e = m-1;
        while(s<=e) {
            int mid = (s+e)/2;
            if(target < matrix[mid][0])
                e = mid;
            else
                s = mid;

            if(s+1 == e || s==e)  {
                if(target<matrix[e][0] && target>=matrix[s][0] && target<=matrix[s][n-1])
                    row = s;
                else if(target>=matrix[e][0] && target<=matrix[e][n-1])
                    row = e;
                else
                    return false;
                break;
            }
        }

        s = 0, e = n-1;
        while(s<=e) {
            int mid = (s+e)/2;
            if(target < matrix[mid][0])
                e = mid-1;
            else if(target > matrix[mid][0])
                s = mid+1;
            else
                return true;

            if(s+1 == e || s == e)  {
                if(target==matrix[row][s] || target==matrix[row][e])
                    return true;

                else
                    return false;

            }
        }




    }
};