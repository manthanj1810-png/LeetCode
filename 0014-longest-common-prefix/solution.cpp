class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int n=size(strs),min=INT_MAX;
      string ans="";
      for(int j=0;j<n;j++){
        if(size(strs[j])<min) min=size(strs[j]);
      }
      for(int i=0;i<min;i++){
        int dummy=0;
        for(int j=0;j<n-1;j++){
            if(strs[j][i]!=strs[j+1][i]){
                dummy=1;
                break;
                }
        }
        if(dummy==0) ans+=strs[0][i];
        else break;
      }
      return ans;
    }
};
