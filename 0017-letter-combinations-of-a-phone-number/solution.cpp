class Solution {
public:
vector<string> res;
string ans;
vector<string> combos={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void help(string digits,int i,string ans){
        if(i>=size(digits)){
            res.push_back(ans);
            return;
        }
        int digit=digits[i]-'0';
        for(int j=0;j<size(combos[digit]);j++){
            help(digits,i+1,ans+combos[digit][j]);
        }
    }
    vector<string> letterCombinations(string digits){
        help(digits,0,ans);
        return res;
    }
};
