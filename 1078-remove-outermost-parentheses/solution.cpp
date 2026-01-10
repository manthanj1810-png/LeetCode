class Solution {
public:
    string removeOuterParentheses(string s) {
       string news = "";
       int i=0;
       for(char c:s){
        if(c=='('){
            if(i>0){
                news+=c;
            } i++;
        }else if(c==')'){
            i--;
            if(i>0) news+=c;
        }
       }
        return news;
    }
   
};
