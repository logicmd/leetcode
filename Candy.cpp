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


class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n=ratings.size();
        if(n==0 || n==1)
            return n;
        //vector<int> candies;
        int cur=1;
        int res=0;
        int flag=0;
        for(int i=0; i<n-1; i++) {
            if(ratings[i+1]>=ratings[i]) {
                //candies[i]=cur;
                //candies.push_back(cur);
                res+=cur;
                if(ratings[i+1]>ratings[i])
                    cur++;
            } else {
                int j=i;
                stack<int> st;
                //st.push(ratings[j]);
                while(j+1<n && ratings[j+1]<ratings[j]) {
                    st.push(ratings[j+1]);
                    j++;
                }

                int c=1;
                int part=1;
                //st.pop();
                //part+=c;
                while(++c && !st.empty()) {
                    st.pop();
                    part+=c;
                }
                part+=max(cur,c);
                i=j+2;
                res+=part;
                if(i<n) {
                    flag=1;
                    if(ratings[i]>ratings[i-1]) {
                        cur=2;
                    } else {
                        cur=1;
                    }
                }
            }
        }
        return res+cur*flag;
    }
};