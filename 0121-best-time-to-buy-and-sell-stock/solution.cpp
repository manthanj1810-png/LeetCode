class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int n=prices.size(),profit=0,mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>mini){
                profit=max(profit,prices[i]-mini);
            }
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};
