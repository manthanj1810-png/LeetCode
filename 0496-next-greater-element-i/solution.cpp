class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
      for(int i=0;i<size(nums1);i++){
        int x=nums1[i];
        for(int j=0;j<size(nums2);j++){
            if(x==nums2[j]){
                int c=0;
                if(j==size(nums2)-1){
                     ans.push_back(-1);
                     break;
                }
                for(int k=j+1;k<size(nums2);k++){
                    if(x<nums2[k]){
                        c=1;
                        ans.push_back(nums2[k]);
                        break;
                    }
                }
                if(!c){
                    ans.push_back(-1);
                    break;
                }
            }
            }
        }
        return ans;
    }
};
