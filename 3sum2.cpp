class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int n=num.size();
        vector<vector<int> > ret;
        for(int i=0; i<n; ++i) {
            int s=i+1, e=n-1;
            while(s<=e) {
                int a=num[i]+num[s]+num[e];
                if(a==0) {
                    vector<int> re;
                    re.push_back(num[i]);
                    re.push_back(num[s]);
                    re.push_back(num[e]);
                    ret.push_back(re);
                } else if (a<0) {
                    s++;
                } else {
                    e--;
                }
            }
        }
        ret.resize(unique(ret.begin(), ret.end())-ret.begin());
        return ret;
    }
};