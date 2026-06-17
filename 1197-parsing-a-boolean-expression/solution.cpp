class Solution {
public:
    char solve(char op,vector<char> values){
        if(op=='!') return values[0]=='t'?'f':'t';
        else if(op=='&'){
            for(char ch:values){
                if(ch=='f') return 'f';
            }
            return 't';
        }
        else{
            for(char ch:values){
                if(ch=='t') return 't';
            }
            return 'f';
        }
        return 'f';
    }
    bool parseBoolExpr(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch==',') continue;
            if(ch==')'){
                vector<char> values; 
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char res= solve(op,values);
                st.push(res);
            }
            else st.push(ch);
        }
        return st.top()=='t';
    }
};
