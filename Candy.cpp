class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=ratings.size();
        if(n==0 || n==1)
            return n;
        int *candies=new int[n];
        candies[0]=1;
        for (int i=1; i<n; )
        {
            if(ratings[i]>ratings[i-1]) {
                candies[i]=candies[i-1]+1;
                ++i;
            }
            else if(ratings[i]==ratings[i-1]) {
                candies[i]=1;
                ++i;
            }
            else {
                int init=i-1;
                int original=candies[i-1];
                while(i<n && ratings[i]<ratings[i-1]) {
                    i++;
                }
                int c=1;
                for(int j=i-1; j>=init; j--) {
                    candies[j]=c;
                    c++;
                }
                candies[init]=max(original, c-1);
            }
        }
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=candies[i];
        return sum;
    }
};

// O(1) space candy
// O(1) 时间反而长，太墨迹了，可读性好差

class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=ratings.size();
        if(n==0 || n==1)
            return n;
        int sum=1;
        int last=1;
        int cur;
        for (int i=1; i<n; )
        {
            if(ratings[i]>ratings[i-1]) {
                cur=last+1;
                sum+=cur;
                last=cur;
                ++i;
            }
            else if(ratings[i]==ratings[i-1]) {
                cur=1;
                sum+=cur;
                last=1;
                ++i;
            }
            else {
                int init=i-1;
                int original=last;
                while(i<n && ratings[i]<ratings[i-1]) {
                    i++;
                }
                int c=1;
                for(int j=i-1; j>=init; j--) {
                    sum+=c;
                    c++;
                }
                if(original>c-1)
                    sum-=(c-1);
                else
                    sum-=original;
                last=1;
            }
        }

        return sum;
    }
};