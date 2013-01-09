// 注意substring的endIndex，要+1

import java.util.ArrayList;
import java.lang.Integer;

public class Restore {
    public static void main(String args[]){
        Restore r = new Restore();
        //String s = "25525511135";
        String s = "010010";
        ArrayList<String> al = r.restoreIpAddresses(s);
        for (String ss:al ) {
            System.out.println(ss);
        }
    }
    public ArrayList<String> restoreIpAddresses(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        //int n = s.length();
        ArrayList<String> IPs = new ArrayList<String>();
        String IP = "";

        getIP(s, 0, IP, 0, IPs);
        return IPs;
    }

    void getIP(String s, int ind, String IP, int n, ArrayList<String> IPs) {
        for (int i = ind+1; i<=s.length() && i<=ind+3; ++i) {
            String subs = s.substring(ind,i);
            if(subs.length() > 1 && subs.charAt(0) == '0') {
                continue;
            }
            int seg = Integer.parseInt(subs);
            if(seg>=0 && seg<256) {
                IP = IP + seg; // cat a new seg
                n++; // n inc
                if(n<4) {
                    IP = IP + '.'; // cat a dot
                    getIP(s, i, IP, n, IPs);
                    IP = IP.substring(0,IP.length()-1); // remove a dot
                } else {
                    if(i==s.length()) {
                        IPs.add(IP);
                        return ;
                    }
                }
                n--; // n dec
                IP = IP.substring(0,IP.lastIndexOf('.')+1); // remove a seg
            }
        }
    }
}