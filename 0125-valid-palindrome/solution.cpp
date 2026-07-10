class Solution {
public:
    bool isPalindrome(string s) {
        string check="";
       for(char ch:s){
            if(ch>='A' && ch<='Z'){
                ch+=32;
                check+=ch;
            }
            else if(ch>='a' && ch<='z') check+=ch;
            else if(ch>='0' && ch<='9') check+=ch;
       }
       int l=0,r=check.size()-1;
       while(l<=r){
        if(check[l]!=check[r]) return false;
        l++;
        r--;
       }
       return true;
    }
};
