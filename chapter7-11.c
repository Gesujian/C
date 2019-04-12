#include <stdio.h>
#include <string.h>
char bubble_sort(char s[])
{
    /*ÆðÅÝ·¨*/
    int i, j, n, tmp;
    n = strlen(s);
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1-i; j++)
        {
            if(s[j] > s[j + 1])
            {
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

void main()
{
    char s[100];
    gets(s);
    bubble_sort(s);
    puts(s);
}
