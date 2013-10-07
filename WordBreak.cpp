class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=s.size();
        if(n==0) {
            if(dict.find("")!=dict.end())
                return true;
            return false;
        }
        if(dict.size()==0)
            return false;

        int maxlen=0; //Trick
        for(unordered_set<string>::iterator its=dict.begin(); its!=dict.end(); its++) {
            if((*its).size()>maxlen)
                maxlen=(*its).size();
        } //Trick

        bool *dp=new bool[n];

        for(int i=0; i<n; i++) {
            string str=s.substr(0,i+1);
            if(dict.find(str)!=dict.end()) {
                dp[i]=true;
                continue;
            }

            bool f=false;
            for(int j=max(0, i-maxlen-1); j<i; j++) { //Trick
                if(dp[j] && dict.find(s.substr(j+1, i-j))!=dict.end()) {
                    f=true;
                    break;
                }
            }
            dp[i]=f;
        }
        return dp[n-1];

    }
};