class Solution {
public:
    double revpow(double x, int n){
        if(n==0) return 1;
        double half=revpow(x,n/2);
        if(n%2==0) return half*half;
        return x*half*half;
    }
    double myPow(double x, int n) {
        long long N=n;
       if(N<0){
        return 1/revpow(x,-N);
       }
       return revpow(x,N);  
    }
};
