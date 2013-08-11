class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        int n=num.size();
        ret.push_back(num);
        if (n==1)   return ret;


        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(num[i],num[j]);
                ret.push_back(num);
                swap(num[i],num[j]);
            }
        }
        return ret;
    }
};