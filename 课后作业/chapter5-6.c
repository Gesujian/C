#include <stdio.h>
int factorial(int n)
{
    /*��n�Ľ׳�*/
    if (n==1) return 1;
    return n*factorial(n-1);
}
void main()
{
    /*����1-20�Ľ׳˺�*/
    int i, n, result;
    n = 20;
    result = 0; // ������
    for(i=1; i<=n; i++) result += factorial(i);
    printf("1!+2!+3!+������+20! = %d", result);
}
