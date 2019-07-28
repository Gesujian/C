#include <stdio.h>
void main()
{
    /*求分数数列前二十项和*/
    double tmp, fz=2, fm=1;
    int  i, n=20;
    double result=0;
    for (i=0; i<n; i++)
    {
        result += fz/fm;
        tmp = fz;
        fz = fz+fm;
        fm = tmp;
    }
    printf("分数数列前%d项和为：%lf", n, result);

}
