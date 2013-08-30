class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int n = num.size();
        vector<vector<int> > vv;
        unordered_map<int, set<pair<int, int> > > hash_map;
        for(int i=0; i<n-1; ++i) {
            for(int j=0; j<n; ++j) {
                int s=num[i]+num[j];
                if(hash_map.find(s)==hash_map.end()) {
                    set<pair<int, int>> st;
                    st.insert(make_pair(i, j));
                    hash_map.insert(make_pair(s, st));
                } else {
                    hash_map[s].insert(make_pair(i, j));
                }
            }
        }

        for(unordered_map<int, set<pair<int, int> > >::iterator its=hash_map.begin();
            its!=hash_map.end(); its++) {
            int a = its->first;
            unordered_map<int, set<pair<int, int> > >::iterator fin = hash_map.find(target-a);
            if(fin!=hash_map.end()) {
                set<pair<int, int>> list1=its->second;
                for(set<pair<int, int>>::iterator iii=list1.begin(); iii!=list1.end(); iii++) {
                    set<int> st;
                    st.insert(iii->first);
                    st.insert(iii->second);

                    set<pair<int, int>> list=fin->second;
                    for(set<pair<int, int>>::iterator ii=list.begin(); ii!=list.end(); ii++) {
                        set<int> st_copy(st);
                        st_copy.insert(ii->first);
                        st_copy.insert(ii->second);
                        if(st_copy.size() == 4) {
                            vector<int> v;
                            for(set<int>::iterator it=st_copy.begin(); it!=st_copy.end(); it++) {
                                v.push_back(num[*it]);
                            }
                            vv.push_back(v);
                        }
                    }
                }

            }
        }
        sort(vv.begin(), vv.end());
        vv.resize(unique(vv.begin(), vv.end())-vv.begin());

        return vv;
    }
};