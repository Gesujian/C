#include <stdio.h>
void main()
{
    /*100m�ߴ��ͷ���*/
    int  n=10,i;
    float result=0, h=100;
    for (i=0; i<10; i++)
    {
        result = i==0? 100:result+h*2;
        h = h/2;
        printf("��%d�Σ�result=%f,h=%f\n",i+1, result, h);
    }
    printf("10 result=%10fM\n",result);
    printf("10 h     =%10fM",h);
}
