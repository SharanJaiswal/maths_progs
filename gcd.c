// Negative numbers are handled at the calling function

#include<stdio.h>

unsigned long long gcd_itr(unsigned long long a, unsigned long long b)
{
    if (a == 0 && b == 0) return 0;
    else
    {
        unsigned long long k, m, rem;
        if(a >= b)
        {
            k = a;
            m = b;
        }
        else
        {
            k = b;
            m = a;
        }

        while(m)
        {
            rem = k%m;
            k = m;
            m = rem;
        }
        return k;
    }
}

unsigned long long act_gcd_rec(unsigned long long k, unsigned long long m)
{
    if (m == 0)
    {
        return k;
    }
    else
    {
        return act_gcd_rec(m, k%m);
    }
}

unsigned long long gcd_rec(unsigned long long a, unsigned long long b)
{
    unsigned long long k, m;
    if(a >= b)
    {
        k = a;
        m = b;
    }
    else
    {
        k = b;
        m = a;
    }
    return act_gcd_rec(k, m);
}

int main()
{
    #include"fileio.h"
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (int)gcd_itr(a, b));
    printf("%llu\n", gcd_rec(a, b));
    return 0;
}