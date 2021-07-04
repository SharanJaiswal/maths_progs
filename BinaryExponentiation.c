// this program can handle floating point base. Both base and exp can be +ve -ve 0 . exp shall belongs to Z.

#include<stdio.h>

long double bin_exp_itr(long double base, long long exp)
{
    long double res = 1;
    int flag;
    if(exp < 0)
    {
        flag = 1;
        exp = -exp;
    }
    while(exp)
    {
        if(exp & 1)
        {
            res = res * base;
        }
        base *= base;
        exp = exp >> 1;
    }
    return (flag) ? 1/res : res;
}

long double bin_exp_rec(long double base, long long exp)
{
    if(exp == 0)
    {
        return 1;
    }
    else if(exp > 0)
    {
        int res = bin_exp_rec(base, exp/2);
        if(exp % 2 == 1) 
        {
            return res * res * base;
        }
        else
        {
            return res * res;
        }
    }
    else if(exp < 0)
    {
        return 1/bin_exp_rec(base, -exp);
    }
}

int main()
{
    #include"fileio.h"
    long double base; // because multiplications are happening over and using base only. It can be -ve.
    long long exp;    // exp is just for checking the odd/even/LSB. Hence it can't be in floating-point. It can be -ve.
    scanf("%Lf %lld", &base, &exp);
    printf("%Lf\n", bin_exp_itr(base, exp));
    printf("%Lf\n", bin_exp_rec(base, exp));
    return 0;
}