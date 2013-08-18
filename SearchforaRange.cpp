class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        int s=0;
        int e=n-1;
        int m=(s+e)/2;
        while (s<=e) {
            if(target<A[m]) {
                e=m-1;
                m=(s+e)/2;
            } else if(target>A[m]) {
                s=m+1;
                m=(s+e)/2;
            } else {
                int i=m;
                while(i>=1 && A[i-1]>=target) {
                    i--;
                }
                if(i>=1 && A[i-1]<target && A[i]>=target) {
                    v.push_back(i-1);
                    v.push_back(i);
                    return v;
                } else {
                    v.push_back(-1);
                    v.push_back(-1);
                    return v;
                }
            }
        }
        int i=s;
        if(target>A[s]) {
            while(i>=1 && A[i-1]>=target) {
                i--;
            }
            if(i>=1 && A[i-1]<target && A[i]>=target) {
                v.push_back(i-1);
                v.push_back(i);
                return v;
            } else {
                v.push_back(-1);
                v.push_back(-1);
                return v;
            }
        } else {
            while(i<n-1 && A[i+1]<=target) {
                if(A[i+1]==target) {
                    v.push_back(i);
                    v.push_back(i+1);
                    return v;
                }
                i++;
            }
            if(i+1<n && A[i+1]<=target && A[i]>target) {
                v.push_back(i);
                v.push_back(i+1);
                return v;
            } else {
                v.push_back(-1);
                v.push_back(-1);
                return v;
            }
        }
    }
};