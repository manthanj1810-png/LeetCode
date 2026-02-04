class Solution {
public:
    int numberOfSubstrings(string s) {
      int n=size(s),l=0,r=0,count=0;
      unordered_map<char,int> mp;
      while(r<n){
        mp[s[r]]++;
        
        while(mp['a']>0 && mp['b']>0 && mp['c']>0){
            count+=n-r;
            mp[s[l]]--;
            l++;
        }
        r++;
      }
      return count;
    }
};
