#include <stdio.h>
int factorial(int n)
{
    /*求n的阶乘*/
    if (n==1) return 1;
    return n*factorial(n-1);
}
void main()
{
    /*计算1-20的阶乘和*/
    int i, n, result;
    n = 20;
    result = 0; // 保存结果
    for(i=1; i<=n; i++) result += factorial(i);
    printf("1!+2!+3!+···+20! = %d", result);
}
