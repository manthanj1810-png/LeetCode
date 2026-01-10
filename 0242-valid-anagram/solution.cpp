class Solution {
public:
    bool isAnagram(string s, string t) {
     int n=s.length(),m=t.length();
     vector<int> arr(26,0);
     if(n!=m) return false;
     else{
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            arr[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
     }
     return true;
    }
};
