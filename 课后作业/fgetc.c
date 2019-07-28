
#include<stdio.h>
void main()
{
    char ch;
    printf("ÇëÊäÈë×Ö·û´®")£»
    ch=getchar();
    while (ch!='#')
    {
        putchar(ch);
        ch=getchar();
    }
    putchar(10);
}
