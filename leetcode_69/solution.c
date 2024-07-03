int mySqrt(int x) {
    if (x<2)
    {
        return x;
    }
    long left = 1;
    long right = x;
    long midsquared = -1000;
    long mid = -1000;
    while(right>=left)
    {
        mid = (long) ((long)(right+left)/2);
        midsquared = (long) mid*mid ;
        if(midsquared == x)
        {
            return mid;
        }
        else if(midsquared>x)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return (int) round(right);
}
