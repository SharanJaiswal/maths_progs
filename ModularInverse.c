// a^-1 mod P is called modular inverse of a. It is generally not equal to inverse of a. Both are different.
// Fermat Little Theorem
// (a^P - a) mod P = 0 ----> (this) is multiple of P
// modular arithmetic only applied on integral numbers
#include <stdio.h>
#define PRIME 1000000007

long long mod_bin_exp(long long base, long long exp, long long mod)
{
    long long res = 1;
    // here since exp is PRIME which has alwyas to be +ve for modular arithmetic, so there wont be negative exp.
    while(exp)
    {
        if(exp & 1)
        {
            res = ((res%mod) * (base%mod)) % mod;
        }
        base = ((base%mod) * (base%mod)) % mod;
        exp = exp >> 1;
    }
    return res;
}

// you cant pass macro as an argument to a normal function unless function itself is a macro, or value of macro is just normal variable whose value is being passed as an argument
long long modularInverse(long long a)
{
    long long exp = PRIME;
    return mod_bin_exp(a, exp-2, exp) % PRIME;
}

int main()
{
    #include "fileio.h"
    long long a;
    scanf("%lld", &a);
    printf("%lld", modularInverse(a));
    return 0;
}