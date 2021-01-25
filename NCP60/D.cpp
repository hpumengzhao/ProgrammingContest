/**
   function : work out ax + by = c  ->(x, y) and request that x is least positive integer.
   date : 2017.11.5
   author : LSC
   code : c++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
long long int x, y, d;// (x, y) ax+by = Gcd(a, b)的其中的一个解，d 是（a, b）最大公约数

LL Gcd(LL a, LL b)// 欧几里德算法（辗转相除法）求解最大公约数
{
    return (b == 0)? a : Gcd(b, a%b);
}

void ex_gcd(LL a, LL b)// 扩展欧几里德 算法
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        d = a;
    }
    else
    {
        ex_gcd(b, a%b);
        LL temp = x;
        x = y;
        y = temp - a/b*y;
    }
}

int main()
{
    LL a, b, C, gcd,dd;

    scanf("%lld%lld%lld%lld", &a, &b,&dd,&C);
    srand(time(NULL));
    gcd = Gcd(a, b);
    while(1){
        LL z1=rand()%(C/dd);
        if(dd*z1>C) continue;
        LL c=C-dd*z1;
        if(c % gcd != 0){
            continue;
        }
        else
        {
            ex_gcd(a, b);
            LL x1, y1, b1;
            b1 = b/gcd;
            x1 = (x + b1) * (c/gcd);
            x1 = (x1 % b1 + b1) % b1;// 求解出 x 的 最小正整数解
            y1 = (c - a*x1) / b;
            if(x1>=0&&y1>=0&&z1>=0){
                printf("%lld %lld %lld\n", x1, y1,z1);
                return 0;
            }
        }
    }
    return 0;
}