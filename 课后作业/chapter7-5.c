#include <stdio.h>
#include <string.h>
char rev(char s[])
{
    /*×ª±ä´æ´¢Ë³Ðò*/
    int i, n, t;
    char tmp;
    n = strlen(s);
    t = n%2==0? n/2:(n-1)/2;
    for (i=0; i<t; i++)
    {
        tmp = s[i];
        s[i]=s[n-1-i];
        s[n-1-i] = tmp;
    }
}

void main()
{
    char s[100];
    printf("ÇëÊäÈëÄãµÄ×Ö·û´®£º\n")
    gets(s);
    rev(s);
    puts(s);
}
