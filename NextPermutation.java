class NextPermutation {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size <= 1) {
            return ;
        }
        vector<int>::iterator i = num.end();
        --i;
    }
};