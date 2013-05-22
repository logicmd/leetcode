class Solution {
public:
    bool isPrlindrome(string s, int i, int j) {
        bool flag = true;
        while (i > j) {
            if(s[i] == s[j]) {
                continue;
            } else {
                flag = false;
                break;
            }
        }
        return flag;
    }

    void dfs(string s, int i, int j, vector<string> &cur, vector<vector<string>> &set) {
        int n = s.size();
        for(int i = 0; ; i<n) {
            for(int j = i; j++; j<n) {
                if(isPrindrome(s, i, j)) {
                    cur.push_back(s.substr(i, j));
                }
            }
            i = j+1;
        }


    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> set;

    }
};