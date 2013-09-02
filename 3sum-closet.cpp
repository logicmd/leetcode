class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());

        int n = num.size();
        int minin = 1<<30-1;
        int res;

        for (int i=0; i<n; i++)
        {
            int s = i+1, e = n-1;
            while (s<e)
            {
                int sum = num[i]+num[s]+num[e];
                if (abs(sum-target)<minin)
                {
                    minin = abs(sum-target);
                    res=sum;

                }
                if (sum==target) {
                    s++; e--;
                } else {
                    if (sum-target>0) e--;
                    else  s++;
                }
            }
        }
        return res;
    }
};