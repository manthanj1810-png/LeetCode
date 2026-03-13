class Solution {
public:
    void help(int n,int cnt,vector<string> &s,string &t){
        if(n==0){
            s.push_back(t);
            return;
        }
        if(cnt<n){
            t.push_back('(');
            help(n,cnt+1,s,t);
            t.pop_back();
        }
        if(!t.empty() && cnt!=0){
            t.push_back(')');
            help(n-1,cnt-1,s,t);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        string t;
        help(n,0,s,t);
        return s;
    }
};
