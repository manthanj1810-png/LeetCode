class Solution {
public:

    void dfs(int pos, string num, long long target,
             long long value, long long prev,
             string expr, vector<string>& ans){

        if(pos == num.size()){
            if(value == target) ans.push_back(expr);
            return;
        }

        for(int i = pos; i < num.size(); i++){

            if(i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i-pos+1);
            long long cur = stoll(part);

            if(pos == 0){
                dfs(i+1, num, target, cur, cur, part, ans);
            }
            else{

                dfs(i+1, num, target,
                    value + cur, cur,
                    expr + "+" + part, ans);

                dfs(i+1, num, target,
                    value - cur, -cur,
                    expr + "-" + part, ans);

                dfs(i+1, num, target,
                    value - prev + prev*cur,
                    prev*cur,
                    expr + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(0, num, target, 0, 0, "", ans);
        return ans;
    }
};
