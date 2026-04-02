class Solution {
public:
    string minWindow(string s, string t) {
      int n=s.size(),m=t.size(),minlen=1e9,cnt=0,l=0,r=0,stin=-1;
      vector<int> hash(265,0);
      for(auto it:t){
        hash[it]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    stin=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return stin==-1?"" : s.substr(stin,minlen);
    }
};
