class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left=L;
        vector<string> ret;
        vector<string>().swap(ret);
        vector<string> con;

        if(L==0) {
            ret.push_back("");
            return ret;
        }
        
        for(vector<string>::iterator it=words.begin(); it!=words.end(); it++) {
            left-=(*it).size();
            if(con.size()>0) {
                left--;
            }
            if(left>=0){
                con.push_back(*it);
            } 
            if(left <0 || it+1==words.end()) {
                int wn=con.size();
                string str;
                if(left < 0 && it+1!=words.end()) {
                    
                    left+=(*it).size();
                    buildStr(wn, left, con, str);
                    ret.push_back(str);
                    
                    vector<string>().swap(con);
                    con.push_back(*it);
                    left=L-(*it).size();
                    
                } else if(left >= 0 && it+1==words.end()) {
                    
                    buildStr(wn, left, con, str);
                    ret.push_back(str);
                    
                } else {
                    
                    left+=(*it).size();
                    buildStr(wn, left, con, str);
                    ret.push_back(str);

                    vector<string>().swap(con);
                    con.push_back(*it);
                    left=L-(*it).size();
                    buildStr(wn, left, con, str);

                    ret.push_back(str);    
                } 
            }
        }

        return ret;


    }

    void buildStr(int wn, int left, vector<string> &con, string &str) {
        str="";
        if(wn>=2) {
            int lleft=left;
            
            for(vector<string>::reverse_iterator conit=con.rbegin(); conit!=con.rend(); conit++){
                str.insert(0,*conit);
                int spn=lleft/wn;
                
                for(int i=0; i<spn+1; i++)
                    str.insert(0," ");
                
                lleft-=spn;
                wn--;
            }    
        } else {
            str.append(*(con.begin()));
            for(int i=0; i<left; i++)
                str.append(" ");
        }
    }

};
