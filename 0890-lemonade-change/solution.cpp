class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      unordered_map<int,int> mp;
      int n=size(bills);
      for(int i=0;i<n;i++){
        int change=bills[i]-5;
        mp[bills[i]]++;
        if(change==5){
            if(mp[5]==0) return false;
            else mp[5]--;
        }
        else if(change==15){
            if(mp[5]==0) return false;
            else if(mp[10]==0 && !(mp[5]>2)) return false;
            else{
                if(mp[10]==0) mp[5]-=3;
                else{
                    mp[10]--;
                    mp[5]--;
                }
            }
        }
      } 
      return true; 
    }
};
