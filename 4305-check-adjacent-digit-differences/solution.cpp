class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
      int n=s.size();
        for(int i=0;i<n-1;i++){
            int x=abs(s[i]-s[i+1]);
            if(x>2) return false;
        }
        return true;
    }
};
