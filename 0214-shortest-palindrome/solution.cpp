class Solution {
public:
    string shortestPalindrome(string s) {
      int m=s.size();
      
      int len=0,i=1;
      string rev=s;
      reverse(rev.begin(),rev.end());
      string t= s+"#"+rev;
      int n=t.size();
      vector<int> lps(n,0);
      while(i<n){
        if(t[i]==t[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0)i++;
            else len=lps[len-1];
        }
      }
      int l=lps[n-1];
      return rev.substr(0,m-l)+s; 
    }
};
