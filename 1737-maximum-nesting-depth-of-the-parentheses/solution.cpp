class Solution {
public:
    int maxDepth(string s) {
      int n=size(s),i=0,cleft=0,cright=0;
      while(i<n){
        if(s[i]=='('){
            cleft++;
            cright=max(cleft,cright);
        }
        else if(s[i]==')'){
            cleft--;
        }
         i++;
      } 
      return cright; 
    }
};
