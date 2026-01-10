class Solution {
public:
    string reverseWords(string s) {
     string ans="";
     int j=s.length()-1;
     while(j>=0){
        while(j>=0 && s[j]==' '){
            j--;
        }
        if(j<0) break;
        int end=j;
        while(j>=0 && s[j]!=' '){
            j--;
        }
        string word=s.substr(j+1,end-j);
        if(!ans.empty()) ans+=' ';
        ans+=word;
     }
     return ans;
    }
};
