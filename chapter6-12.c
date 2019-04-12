#include <stdio.h>
void main()
{
    /*加密解密
    明文：I am the best in the Universe!*/
    char massage[] = {"I am the best in the Universe!"};
    //char massage[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    //char massage[] = {"abcdefghijklmnopqrstuvwxyz"};
    int i;
    printf("%s\n", massage);
    //加密
    for (i=0; i<sizeof(massage)-1; i++)
    {
        if (massage[i]>=65 & massage[i]<=90) massage[i] = 65 + 26 - (massage[i]-65+1);
        if (massage[i]>=97 & massage[i]<=122) massage[i] = 97 + 26 - (massage[i]-97+1);

    }
    printf("%s", massage);
    //printf("%d",sizeof(massage)-1);
    //for (i=0; i<)
}
