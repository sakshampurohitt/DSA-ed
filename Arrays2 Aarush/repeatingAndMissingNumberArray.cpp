vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();
    long long sum1=0;
    long long sum3=0;
    for(long long i=0; i<n; i++) {
        sum1+=A[i];
        sum3+=(long long)A[i]*(long long)A[i];
    }
    long long sum2=(n*(n+1))/2;
    long long x_y = sum1-sum2;
    
    long long sum4=(n*(n+1)*(2*n+1))/6;
    long long x2_y2=sum3-sum4;
    long long xPlusY=x2_y2/x_y;
    
    long long repeating = (xPlusY+x_y)/2;
    long long missing = (xPlusY-x_y)/2;
    
    return {repeating, missing};
}
