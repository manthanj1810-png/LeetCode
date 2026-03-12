class Solution {
public:
    int minAddToMakeValid(string s) {
       int cnt1=0,cnt2=0;
       for(char x:s){
        if(x=='(') cnt1++;
        if(x==')'){
            if(cnt1==0) cnt2++;
            else cnt1--;
        }
       }
        return abs(cnt1+cnt2);
    }
};
