#include <stdio.h>
void main()
{
    /*���������ǰ��ʮ���*/
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
    printf("��������ǰ%d���Ϊ��%lf", n, result);

}
