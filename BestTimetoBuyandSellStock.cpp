class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=prices.size();
        if(n==0)    return 0;
        if(n==1)    return prices[0];
        int min = 1<<30 -1 + 1<<30;
        int max = -1<<31;

        int re=0;

        for(int i=0; i<prices.size(); i++) {
            if(prices[i]<min)
                min=prices[i];
            if(prices[i]>max)
                max=prices[i];

            if(max-min>re)
                re=max-min;

        }

        return re;

    }
};