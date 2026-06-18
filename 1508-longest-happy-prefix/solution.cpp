class Solution {
public:
    string longestPrefix(string s) {
      int m=s.size();
      vector<int> lps(m,0);
      int len=0, i=1;
      while(i<m){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0) i++;
            else len=lps[len-1];
        }
      }
      return s.substr(0,lps[m-1]);  
    }
};
