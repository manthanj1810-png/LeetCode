class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=size(s),l=0,r=0,mxl=0;
        unordered_map<char,int> mp;
        while(r<n){
            if(mp[s[r]]>0){
                while(l<=r && mp[s[r]]>0){
                    mp[s[l]]--;
                    l++;
                }
            }
            mxl=max(mxl,r-l+1);
            mp[s[r]]++;
            r++;
            if((n-l)<=mxl) break;
        }
        return mxl;
    }
};
