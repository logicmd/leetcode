class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=ratings.size();
        if(n==0 || n==1)
            return 1;
        for(int i=0; i<n; i++) {
            if(i)
        }
        unordered_map<int, int> hash_map;

        for(int i=0; i<n; i++) {
            if(hash_map.find(ratings[i])==hash_map.end()) {
                hash_map.insert(make_pair(ratings[i], 1));
            } else {
                hash_map[ratings[i]]++;
            }
        }

        sort(ratings.begin(), ratings.end());
        ratings.erase(unique(ratings.begin(), ratings.end()), ratings.end());
        int c=1;
        int res=0;
        for(int i=0; i<n; i++) {
            res+=c*hash_map[ratings[i]];
            c++;
        }
        return res;
    }
};