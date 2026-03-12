class Solution {
public:
    string rle(string &t){
        string temp="";
        int n=size(t);
        for(int i=0;i<n;i++){
            int count=1;
            while(i!=n-1 && t[i]==t[i+1]){
                count++;
                i++;
            }
            temp+= to_string(count);
            temp+= t[i];
        }
        return temp;
    }
    string countAndSay(int n) {
        string ans="1";
       for(int i=1;i<n;i++){
            ans=rle(ans);
        }
       return ans;
    }
};
