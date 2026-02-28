class Solution {
public:
    int divide(int dividend, int divisor) {
        bool ispos=true;
        long long n=dividend,d=divisor;
        if(d==1) return n;
        if(n==d) return 1;
        if(n==INT_MIN && d==-1) return INT_MAX;
        if(n>=0 && d<0) ispos=false;
        else if(n<0 && d>0) ispos=false;
        n=abs(n);
        d=abs(d);
        long long sum=0;
        while(d<=n){
            long long temp=d, p2=1;
            while((temp<<1) <= n){
                temp<<=1;
                p2<<=1;
            }
            n-=temp;
            sum +=p2;
        }

        if(sum>INT_MAX) return INT_MAX;
        if(sum<INT_MIN) return INT_MIN;
        return ispos ? sum:-1*sum;
    }
};
