class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int Size) {
      int n=hand.size();
      if(n%Size!=0) return false;
      map<int,int> freq;
      for(int x: hand) freq[x]++;
      while(!freq.empty()){
        int start=freq.begin()->first;
        for(int i=start;i<start+Size;i++){
            if(!freq.count(i)) return false;
            freq[i]--;
            if(freq[i]==0) freq.erase(i);
            }
        }
        return true;
    }
};
